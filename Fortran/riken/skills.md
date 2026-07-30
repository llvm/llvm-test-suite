# riken F2008テスト統合で得た知見

外部のlitベースFortranテストスイート(RIKEN F2008 conformance tests)を、
llvm-test-suiteのCMake+lit駆動ビルドに統合する作業で得られた、再利用可能な
知見・注意点をまとめる。同種の作業(他のテストスイートの取り込み、riken側の
エラー系テスト対応など)を行う際に参照する。

## 1. 既存の仕組みへの合わせ方

- 単一ソース・ビルド&実行型のテストは `llvm_singlesource()` に乗せるのが
  基本。`Fortran/cray`, `Fortran/UnitTests` と同じパターン。
- ディレクトリ単位で `config.traditional_output = True` /
  `config.single_source = True` を `lit.local.cfg` に書き、
  `file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")` で
  ビルドディレクトリに複製する(lit はビルドディレクトリ側の
  `lit.local.cfg` を見る)。
- 期待出力は「combined stdout+stderr + 末尾に `exit N`」という
  `.reference_output` 形式(`timeit --redirect-output --append-exitstatus`
  相当)。既存の `Fortran/cray/**/*.reference_output` を実例として確認すると
  フォーマットの解釈違いを防げる。
- エラー系(コンパイル失敗を期待する)テストは `llvm_singlesource()` の対象外。
  `Fortran/gfortran/CMakeLists.txt` の `gfortran_add_compile_test()` が
  参考になる — `add_custom_command` でビルド時にコンパイルし、共有のダミー
  実行ファイルを「実行対象」として使い、診断出力を空/`%not diff` と比較する
  パターン。riken の `_cNNN` 系は今回スコープ外としたが、対応する際はここが
  出発点になる。

## 2. CMakeの落とし穴

- **`set(Source ${_sources})` で `_sources` が空だと `Source` 自体が
  undefine される**(「空リスト」ではなく「未定義」になる)。
  `llvm_singlesource()` は `if(DEFINED Source)` でフォールバックの自前 glob
  に切り替わるため、これに気づかず「除外リストで全部除外したはずのディレクト
  リなのに、なぜか全ファイルがビルドされる」という事故になる。
  **対策**: 何かを add する処理全体を `if(_sources) ... endif()` で囲む。
- **同一ディレクトリ内の複数ソースが同名 `module` を宣言していると、
  並列ビルドで `.mod` ファイルが競合する**(`Cannot rename module file
  'm.mod0' to 'm.mod'` のようなエラー)。`llvm_singlesource()` は同一
  ディレクトリの全ターゲットを同じ `CMAKE_CURRENT_BINARY_DIR` でビルドする
  ため。**対策**: ターゲットごとに専用の `Fortran_MODULE_DIRECTORY` を
  `set_target_properties` で与える(`Fortran/gfortran/CMakeLists.txt` の
  `gfortran_make_working_dir()` と同じ発想)。
- コンパイラ固有オプション(例: gfortran の `ERROR STOP` 時の非決定的
  バックトレースを抑える `-fno-backtrace`)は
  `if(CMAKE_Fortran_COMPILER_ID STREQUAL "GNU")` で確実にガードする。
  flang など他コンパイラには存在しない挙動への対処を無条件に適用しない。
- コンパイラ機能の有無(例: `REAL128`)は決め打ちで除外せず、
  `CheckFortranSourceCompiles` で **実際に使われている形**(今回なら
  `iso_fortran_env` の `real128` 定数)を直接プローブするカスタム変数
  (`RIKEN_HAS_REAL128`)を用意する。既存の類似チェック
  (`FORTRAN_HAS_R16`: リテラル `kind=16` をテスト)は、微妙に違う機能を
  見ているだけで実際の使用箇所とは一致しないことがあるので、
  「似たようなチェックが既にあるから流用する」ではなく、テスト対象の
  コードと同じ書き方でプローブし直す方が安全。

## 3. `.reference_output` 生成の方法論

- **最初にやって失敗した方法**: `gfortran file.f90 -o a.out`
  のようにビルドフラグ無しで手元コンパイルして期待値を作る。
  → 最適化レベル依存のコンパイラの挙動差(gfortranのバグ的挙動が
  `-O0`/`-O3` で変わる、`-fno-backtrace` が無いとノイズが混じる、など)により
  「手元で作った期待値」と「実際のCMakeビルドでの出力」が食い違う事故が
  複数件発生した(`28_bessel_001`, `28_bitProcesssing_007`,
  `28_maxlocAndminloc_001` など)。
- **正しい方法**: 必ず実際にCMakeでビルドした(本番と同じ Release/`-O3`等の
  フラグがかかった)バイナリを実行して `.reference_output` を作る。
  「本物の設定でビルド→実行→出力をそのまま期待値にする」を徹底する。
  ゴールデン出力は「こう書いてあるはずだ」という推測ではなく、必ず
  「実際に動かして得た値」にする。
- **非決定性の検出**: 同一バイナリを複数回(今回は3〜5回)実行し、出力が
  毎回変わらないかを確認する。1回だけ実行して「たまたま一致した」ものを
  期待値として採用すると、後で uninitialized memory 由来の非決定的な
  バグ(`28_bitProcesssing_007`)を見逃す。値が実行ごとに変わる場合は
  「たまたま今回はこの値だった」を期待値にするのではなく、そもそも
  そのテストをビルド対象から除外し、理由をコメントで残す。
- 疑わしい挙動(コンパイラのバグらしきもの)を見つけたら、推測で終わらせず
  実際にそのコンパイラで再現確認してから README 等に記録する
  (gfortranでの推測 → flangでの実機確認、の順で裏取りした)。

## 4. ドキュメント化の方針

- 除外したテストは「なぜ除外したか」を `list(REMOVE_ITEM ...)` の行に
  インラインコメントとして残し、詳細説明は `README.md` の Status
  セクションに集約する。理由は必ず次のように分類すると後で扱いやすい:
  - 実コンパイラの確認済みバグ(upstream報告に値するもの)
  - プラットフォーム固有(Linuxでは再現しない可能性が高いもの)
  - 構造的な制約(既存ヘルパーの機能不足によるもの。フィクスチャ欠落、
    副作用ファイルの検証が必要、等)
  - テスト側の期待値自体が誤り(元のコメントの想定が実機と食い違う)
- 「最初の版からの差分」という切り口でサマリーを作ると、統合作業そのものが
  生んだ副産物(見つかったバグ、CMake基盤の一般的な不具合修正)が
  何かを俯瞰しやすい。単に「gfortran版との差分」だけだと、統合以前から
  あった問題との区別がつきにくい。

## 5. 作業プロセス上の注意

- 一時ファイルは必ず指定されたスクラッチパッドディレクトリに置く。`/tmp`
  直書きはツール呼び出し拒否の原因になった。
- 破壊的編集の前に、対象ディレクトリの完全バックアップ(`riken_backup/`
  のようなコピー)を取ってから進めると、大量ファイルの一括変換
  (ディレクティブ除去、reference_output再生成)で安心して試行錯誤できる。
- CMakeLists.txt / lit.local.cfg のような定型ファイルをディレクトリ数分
  (今回36個)手で書くのではなく、除外リストや条件をPythonの辞書で管理する
  生成スクリプト(`gen_cmake.py`)を「唯一の正」として持ち、再実行すれば
  全ファイルが再生成される状態にしておくと、除外理由の追加・修正が
  安全に行える。

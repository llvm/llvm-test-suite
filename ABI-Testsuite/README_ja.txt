このディレクトリには、IA64-ABI テストスイートが格納されています。

テストスイートを Linux 上で実行する場合には、次の手順に従ってください。

1) 「lit」が PYTHONOPATH 内に、FileCheck が PATH 内に設定されていることを確認します。
2) 以下を行います。 
      python linux-x86.py <コンパイラ+引数> test [任意の lit 引数]

   <コンパイラ+引数> は、テストするコンパイラで、任意の <引数> を単一の引数として指定します。以下を参照してください。

      python linux-x86.py clang test                    # clang は、必ず PATH 内に配置してください
      python linux-x86.py /home/me/bin/my-clang test    # 自分で使うコンパイラ、PATH 内にはない
      python linux-x86.py 'clang -m32' test             # 32 ビット モードでテスト
      python linux-x86.py 'clang -O' test               # 最適化を有効化してテスト
      python linux-x86.py 'gcc' test -v                 # -v を lit にパスして gcc をテスト
      python linux-x86.py clang test/basic              # 「basic」ディレクトリのみテスト 
      
linux-x86.py は、小さな実行可能ファイルを実行し、まずこれが 32 ビットのプラットフォームなのか、それとも 64 
ビットのプラットフォームなのかを判定します。次に、テスト用に 2 つある構成の 1 つを選択します。

これ以外の、非 Linux プラットフォームではコンパイラ、リンカ、ランナー (あれば) などを指定するため、python 
スクリプトの編集が必要になります。弊社で提供しているサンプル 
ファイルは、他の「似たような」プラットフォーム向けに変更可能です。しかし、本テストスイートは、リリースされている状態では、x86 Linux 
とそれに類似したプラットフォームのみのサポートとなることにご留意ください。

テストは「test」で開始される複数のディレクトリ内でアレンジできます。pyhthon 
スクリプトは、任意のサブディレクトリに指定できます。ディレクトリ「test/common」には、テストスイートで使用するユーティリティ 
ファイルが含まれます。

ファイルの概要は以下のようになっています。

README.text                         # この README
linux-x86.py                        # 最上位の python スクリプト

test/basic/basic.x                  # 基本構成が正しいことをテストする小ディレクトリ。
test/basic/T_st.x                   # このテストに失敗した場合には、他の何をしても失敗します。

test/common/genselector.c           # テストスイートが使用するユーティリティが格納されているディレクトリ
test/common/select2.h
test/common/testsuite.c
test/common/testsuite.h             

test/lit.site.cfg                   # lit から呼び出されるトップの構成ファイル

test/mangling/arrays.xpp            # マングリング テスト。FileCheck を使用
test/mangling/c++11.xpp
test/mangling/c++11s.xpp
....

test/misc/s2_8a.xpp                 # その他のテスト ディレクトリ
test/misc/s2_8b.x
test/misc/s2_9_5.x
test/misc/s3_1.xpp
...

test/s2_4/T_novirt_1.x              # スペックの特定のセクションに的を絞るテスト
...

test/s2_5/T_vf1.x
test/s2_5/T_vf2.x
...

test/s2_6/T_isc.x
test/s2_6/T_ksc0.x
test/s2_6/T_ksc1.x
...

test/struct_layout_tests/CT_bf.x    #  プレーンな構造体レイアウトのテスト
test/struct_layout_tests/CT_Snen_xaa.x
test/struct_layout_tests/CT_Snen_xab.x
...

test/struct_layout_tests/PACKED/CT_Snen_xaa.x   # パックド構造体のテスト
test/struct_layout_tests/PACKED/CT_Snen_xab.x
...

------------------------------------------------------------------

特記事項：

a) このリリースは、約 290 個のファイルで構成されています。後日、さらに多くのテストをリリースする予定です。
b) ご覧のとおり、テスト ファイル名にはサフィックス「.x」および「.xpp」が付けられます。これは意図的なものです。
   lit.site.cfg 内にはあるメカニズムがあります。このメカニズムは最上位の python ファイルで指定されている「スキップ 
リスト」を調べることにより、「.x」および「.xpp」を、対応する「.c」または「.cpp」ファイルにコピーします。このメカニズムにより、ユーザーは、ファイル
単位ベース、テスト スクリプト単位ベースで、特定のテストを「XFAIL」(expected to fail、失敗が予想される) 
とマークすることが可能になります。 
c) テスト ファイルは、すべてが自己完結型で独立型です。そのため、テスト ファイルは異なるディレクトリに移動したり、削除することができます。
d) ほとんどのファイルは T_*.x または CT_*.x と名付けられており、C コードと C++ 
コードの両方を搭載している「まとめ」ファイルで、「#ifdef 
__cplusplus」で区切られています。こういったファイルのいちばん上にある「//RUN」ヘッダーは、ファイル上で C コンパイラと C++ 
コンパイラを実行させるもので、結果として得られたオブジェクト ファイルをリンクし、テストの実行可能ファイルを作成します。

------------------------------------------------------------------
既知の理由により一部のテストに失敗する場合は、これを取り扱う方法が何通りかあります。

1) skip_list のメカニズムは特定のテストを skip_list に追加することにより、XFAIL とマークします。sample.py を参照してください。
2) テストの実行可能ファイルの結果は、今後のテスト実行と比較するために「Golden Master」として保存することが可能です。
3) 最後に、「test_params[<checker>] は、プレーンな「grep」から、「Golden 
Master」のような、テスト結果に一致する、ユーザーが記述したプログラムに変更することができます。





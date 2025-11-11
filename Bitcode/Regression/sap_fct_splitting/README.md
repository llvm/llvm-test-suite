# SAP function splitting regression test

## Purpose
This tests the correct compilation of `indirectbr` and `blockaddr` in combination with custom cost-based function outlining.

## Regenerate bitcode file
This bitcode test was generated from this high level program:

```
Int32 main() {
  Bool x;
  Int32 counter = test::produce(5);
  while (counter < 10) {
    counter++;
// Creation of subfunction forced here - start
    if (counter >= 8) {
      break; // triggers indirectbr
    } else if (counter >= 4) {
      continue; // triggers indirectbr
    }
// Creation of subfunction forced here - end
    test::consume(counter);
  }
  return 1;
}

```

convert IR to bitcode using this command:

```sh
llvm-as <ir-file> -o <bitcode-file>
```

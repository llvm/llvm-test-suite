%.str_1 = internal constant [32 x sbyte] c"Hello world with %d arguments!\0A\00"

implementation

declare int %printf(sbyte*, ...)

int %main(int %argc, sbyte** %argv) {
        %tmp.0 = call int (sbyte*, ...)* %printf( sbyte* getelementptr ([32 x sbyte]*  %.str_1, long 0, long 0), int %argc )
        ret int 0
}


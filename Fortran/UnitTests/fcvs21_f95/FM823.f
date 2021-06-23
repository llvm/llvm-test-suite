      PROGRAM FM823

C***********************************************************************00010823
C*****  FORTRAN 77                                                      00020823
C*****   FM823                                                          00030823
C*****                       YDASIN - (194)                             00040823
C*****                                                                  00050823
C***********************************************************************00060823
C*****  GENERAL PURPOSE                                         ANS REF 00070823
C*****    TEST INTRINSIC FUNCTION DASIN, DACOS                   15.3   00080823
C*****                                                          TABLE 5 00090823
C*****                                                                  00100823
CBB** ********************** BBCCOMNT **********************************00110823
C****                                                                   00120823
C****            1978 FORTRAN COMPILER VALIDATION SYSTEM                00130823
C****                          VERSION 2.1                              00140823
C****                                                                   00150823
C****                                                                   00160823
C****           SUGGESTIONS AND COMMENTS SHOULD BE FORWARDED TO         00170823
C****          NATIONAL INSTITUTE OF STANDARDS AND TECHNOLOGY           00180823
C****               SOFTWARE STANDARDS VALIDATION GROUP                 00190823
C****                      BUILDING 225  RM A266                        00200823
C****                     GAITHERSBURG, MD  20899                       00210823
C****                                                                   00220823
C****                                                                   00230823
C****                                                                   00240823
CBE** ********************** BBCCOMNT **********************************00250823
C*****                                                                  00260823
C*****    S P E C I F I C A T I O N S SEGMENT 194                       00270823
        DOUBLE PRECISION AVD, BVD, CVD, DVCORR                          00280823
C*****                                                                  00290823
CBB** ********************** BBCINITA **********************************00300823
C**** SPECIFICATION STATEMENTS                                          00310823
C****                                                                   00320823
      CHARACTER ZVERS*13, ZVERSD*17, ZDATE*17, ZPROG*5, ZCOMPL*20,      00330823
     1          ZNAME*20, ZTAPE*10, ZPROJ*13, REMRKS*31, ZTAPED*13      00340823
CBE** ********************** BBCINITA **********************************00350823
CBB** ********************** BBCINITB **********************************00360823
C**** INITIALIZE SECTION                                                00370823
      DATA  ZVERS,                  ZVERSD,             ZDATE           00380823
     1      /'VERSION 2.1  ',  '93/10/21*21.02.00',  '*NO DATE*TIME'/   00390823
      DATA       ZCOMPL,             ZNAME,             ZTAPE           00400823
     1      /'*NONE SPECIFIED*', '*NO COMPANY NAME*', '*NO TAPE*'/      00410823
      DATA       ZPROJ,           ZTAPED,         ZPROG                 00420823
     1      /'*NO PROJECT*',   '*NO TAPE DATE',  'XXXXX'/               00430823
      DATA   REMRKS /'                               '/                 00440823
C**** THE FOLLOWING 9 COMMENT LINES (CZ01, CZ02, ...) CAN BE REPLACED   00450823
C**** FOR IDENTIFYING THE TEST ENVIRONMENT                              00460823
C****                                                                   00470823
CZ01  ZVERS  = 'VERSION OF THE COMPILER VALIDATION SYSTEM'              00480823
CZ02  ZVERSD = 'CREATION DATE/TIME OF THE COMPILER VALIDATION SYSTEM'   00490823
CZ03  ZPROG  = 'PROGRAM NAME'                                           00500823
CZ04  ZDATE  = 'DATE OF TEST'                                           00510823
CZ05  ZCOMPL = 'COMPILER IDENTIFICATION'                                00520823
CZ06  ZPROJ  = 'PROJECT NUMBER/IDENTIFICATION'                          00530823
CZ07  ZNAME  = 'NAME OF USER'                                           00540823
CZ08  ZTAPE  = 'TAPE OWNER/ID'                                          00550823
CZ09  ZTAPED = 'DATE TAPE COPIED'                                       00560823
C                                                                       00570823
      IVPASS = 0                                                        00580823
      IVFAIL = 0                                                        00590823
      IVDELE = 0                                                        00600823
      IVINSP = 0                                                        00610823
      IVTOTL = 0                                                        00620823
      IVTOTN = 0                                                        00630823
      ICZERO = 0                                                        00640823
C                                                                       00650823
C     I01 CONTAINS THE LOGICAL UNIT NUMBER FOR THE CARD READER.         00660823
      I01 = 05                                                          00670823
C     I02 CONTAINS THE LOGICAL UNIT NUMBER FOR THE PRINTER.             00680823
      I02 = 06                                                          00690823
C                                                                       00700823
CX010   REPLACED BY FEXEC X-010 CONTROL CARD (CARD-READER UNIT NUMBER). 00710823
C     THE CX010 CARD IS FOR OVERRIDING THE PROGRAM DEFAULT I01 = 5      00720823
CX011   REPLACED BY FEXEC X-011 CONTROL CARD.  CX011 IS FOR SYSTEMS     00730823
C     REQUIRING ADDITIONAL STATEMENTS FOR FILES ASSOCIATED WITH CX010.  00740823
C                                                                       00750823
CX020   REPLACED BY FEXEC X-020 CONTROL CARD (PRINTER UNIT NUMBER).     00760823
C     THE CX020 CARD IS FOR OVERRIDING THE PROGRAM DEFAULT I02= 6       00770823
CX021   REPLACED BY FEXEC X-021 CONTROL CARD.  CX021 IS FOR SYSTEMS     00780823
C     REQUIRING ADDITIONAL STATEMENTS FOR FILES ASSOCIATED WITH CX020.  00790823
C                                                                       00800823
CBE** ********************** BBCINITB **********************************00810823
      NUVI = I02                                                        00820823
      IVTOTL = 12                                                       00830823
      ZPROG = 'FM823'                                                   00840823
CBB** ********************** BBCHED0A **********************************00850823
C****                                                                   00860823
C**** WRITE REPORT TITLE                                                00870823
C****                                                                   00880823
      WRITE (I02, 90002)                                                00890823
      WRITE (I02, 90006)                                                00900823
      WRITE (I02, 90007)                                                00910823
      WRITE (I02, 90008)  ZVERS, ZVERSD                                 00920823
      WRITE (I02, 90009)  ZPROG, ZPROG                                  00930823
      WRITE (I02, 90010)  ZDATE, ZCOMPL                                 00940823
CBE** ********************** BBCHED0A **********************************00950823
C*****                                                                  00960823
C*****    HEADER FOR SEGMENT 194                                        00970823
        WRITE(NUVI,19400)                                               00980823
19400   FORMAT(" ", / "  YDASIN - (194) INTRINSIC FUNCTIONS" //         00990823
     1         "  DASIN, DACOS (DOUBLE PRECISION ARCSINE, ARCCOSINE)" //01000823
     2         "  ANS REF. - 15.3" )                                    01010823
CBB** ********************** BBCHED0B **********************************01020823
C**** WRITE DETAIL REPORT HEADERS                                       01030823
C****                                                                   01040823
      WRITE (I02,90004)                                                 01050823
      WRITE (I02,90004)                                                 01060823
      WRITE (I02,90013)                                                 01070823
      WRITE (I02,90014)                                                 01080823
      WRITE (I02,90015) IVTOTL                                          01090823
CBE** ********************** BBCHED0B **********************************01100823
C*****                                                                  01110823
        WRITE(NUVI,19401)                                               01120823
19401   FORMAT("0",8X,"TEST OF DASIN" )                                 01130823
C*****                                                                  01140823
CT001*  TEST 1                  -1.0D0 FOR PRINCIPAL VALUE AT ENDPOINTS 01150823
           IVTNUM = 1                                                   01160823
        BVD = -1.0D0                                                    01170823
        AVD = DASIN(BVD)                                                01180823
           IF (AVD +  0.1570796328D+01) 20010, 10010, 40010             01190823
40010      IF (AVD +  0.1570796326D+01) 10010, 10010, 20010             01200823
10010      IVPASS = IVPASS + 1                                          01210823
           WRITE (NUVI, 80002) IVTNUM                                   01220823
           GO TO 0011                                                   01230823
20010      IVFAIL = IVFAIL + 1                                          01240823
           DVCORR = -1.5707963267948966192D+00                          01250823
           WRITE (NUVI, 80031) IVTNUM, AVD, DVCORR                      01260823
 0011      CONTINUE                                                     01270823
CT002*  TEST 2                  +1.0D0 FOR PRINCIPAL VALUE AT ENDPOINTS 01280823
           IVTNUM = 2                                                   01290823
        AVD = DASIN(1.0D0)                                              01300823
           IF (AVD -  0.1570796326D+01) 20020, 10020, 40020             01310823
40020      IF (AVD -  0.1570796328D+01) 10020, 10020, 20020             01320823
10020      IVPASS = IVPASS + 1                                          01330823
           WRITE (NUVI, 80002) IVTNUM                                   01340823
           GO TO 0021                                                   01350823
20020      IVFAIL = IVFAIL + 1                                          01360823
           DVCORR =  1.5707963267948966192D+00                          01370823
           WRITE (NUVI, 80031) IVTNUM, AVD, DVCORR                      01380823
 0021      CONTINUE                                                     01390823
CT003*  TEST 3                                  THE VALUE -DSQRT(0.5D0) 01400823
           IVTNUM = 3                                                   01410823
        BVD = -(DSQRT(2.0D0) / 2.0D0)                                   01420823
        AVD = DASIN(BVD)                                                01430823
           IF (AVD +  0.7853981638D+00) 20030, 10030, 40030             01440823
40030      IF (AVD +  0.7853981630D+00) 10030, 10030, 20030             01450823
10030      IVPASS = IVPASS + 1                                          01460823
           WRITE (NUVI, 80002) IVTNUM                                   01470823
           GO TO 0031                                                   01480823
20030      IVFAIL = IVFAIL + 1                                          01490823
           DVCORR = -0.78539816339744830962D+00                         01500823
           WRITE (NUVI, 80031) IVTNUM, AVD, DVCORR                      01510823
 0031      CONTINUE                                                     01520823
CT004*  TEST 4                                          THE VALUE 0.5D0 01530823
           IVTNUM = 4                                                   01540823
        AVD = DASIN(1.0D0 / 2.0D0)                                      01550823
           IF (AVD -  0.5235987753D+00) 20040, 10040, 40040             01560823
40040      IF (AVD -  0.5235987759D+00) 10040, 10040, 20040             01570823
10040      IVPASS = IVPASS + 1                                          01580823
           WRITE (NUVI, 80002) IVTNUM                                   01590823
           GO TO 0041                                                   01600823
20040      IVFAIL = IVFAIL + 1                                          01610823
           DVCORR =  0.52359877559829887308D+00                         01620823
           WRITE (NUVI, 80031) IVTNUM, AVD, DVCORR                      01630823
 0041      CONTINUE                                                     01640823
CT005*  TEST 5                             AN ARGUMENT OF LOW MAGNITUDE 01650823
           IVTNUM = 5                                                   01660823
        AVD = DASIN(-1.0D-13)                                           01670823
           IF (AVD +  0.1000000001D-12) 20050, 10050, 40050             01680823
40050      IF (AVD +  0.9999999995D-13) 10050, 10050, 20050             01690823
10050      IVPASS = IVPASS + 1                                          01700823
           WRITE (NUVI, 80002) IVTNUM                                   01710823
           GO TO 0051                                                   01720823
20050      IVFAIL = IVFAIL + 1                                          01730823
           DVCORR = -1.0000000000000000000D-13                          01740823
           WRITE (NUVI, 80031) IVTNUM, AVD, DVCORR                      01750823
 0051      CONTINUE                                                     01760823
C*****                                                                  01770823
        WRITE(NUVI,19407)                                               01780823
19407   FORMAT("0",8X,"TEST OF DACOS" )                                 01790823
C*****                                                                  01800823
CT006*  TEST 6                  -1.0D0 FOR PRINCIPAL VALUE AT ENDPOINTS 01810823
           IVTNUM = 6                                                   01820823
        BVD = -1.0D0                                                    01830823
        AVD = DACOS(BVD)                                                01840823
           IF (AVD -  0.3141592652D+01) 20060, 10060, 40060             01850823
40060      IF (AVD -  0.3141592655D+01) 10060, 10060, 20060             01860823
10060      IVPASS = IVPASS + 1                                          01870823
           WRITE (NUVI, 80002) IVTNUM                                   01880823
           GO TO 0061                                                   01890823
20060      IVFAIL = IVFAIL + 1                                          01900823
           DVCORR =  3.1415926535897932384D+00                          01910823
           WRITE (NUVI, 80031) IVTNUM, AVD, DVCORR                      01920823
 0061      CONTINUE                                                     01930823
CT007*  TEST 7              +1.0D0 TO TEST PRINCIPAL VALUE AT ENDPOINTS 01940823
           IVTNUM = 7                                                   01950823
        AVD = DACOS(1.0D0)                                              01960823
           IF (AVD +  0.5000000000D-09) 20070, 10070, 40070             01970823
40070      IF (AVD -  0.5000000000D-09) 10070, 10070, 20070             01980823
10070      IVPASS = IVPASS + 1                                          01990823
           WRITE (NUVI, 80002) IVTNUM                                   02000823
           GO TO 0071                                                   02010823
20070      IVFAIL = IVFAIL + 1                                          02020823
           DVCORR =  0.00000000000000000000D+00                         02030823
           WRITE (NUVI, 80031) IVTNUM, AVD, DVCORR                      02040823
 0071      CONTINUE                                                     02050823
CT008*  TEST 8                                  THE VALUE -DSQRT(0.5D0) 02060823
           IVTNUM = 8                                                   02070823
        BVD = -(DSQRT(2.0D0) / 2.0D0)                                   02080823
        AVD = DACOS(BVD)                                                02090823
           IF (AVD -  0.2356194489D+01) 20080, 10080, 40080             02100823
40080      IF (AVD -  0.2356194492D+01) 10080, 10080, 20080             02110823
10080      IVPASS = IVPASS + 1                                          02120823
           WRITE (NUVI, 80002) IVTNUM                                   02130823
           GO TO 0081                                                   02140823
20080      IVFAIL = IVFAIL + 1                                          02150823
           DVCORR =  2.3561944901923449288D+00                          02160823
           WRITE (NUVI, 80031) IVTNUM, AVD, DVCORR                      02170823
 0081      CONTINUE                                                     02180823
CT009*  TEST 9                                          THE VALUE 0.5D0 02190823
           IVTNUM = 9                                                   02200823
        AVD = DACOS(1.0D0 / 2.0D0)                                      02210823
           IF (AVD -  0.1047197550D+01) 20090, 10090, 40090             02220823
40090      IF (AVD -  0.1047197552D+01) 10090, 10090, 20090             02230823
10090      IVPASS = IVPASS + 1                                          02240823
           WRITE (NUVI, 80002) IVTNUM                                   02250823
           GO TO 0091                                                   02260823
20090      IVFAIL = IVFAIL + 1                                          02270823
           DVCORR =  1.0471975511965977461D+00                          02280823
           WRITE (NUVI, 80031) IVTNUM, AVD, DVCORR                      02290823
 0091      CONTINUE                                                     02300823
CT010*  TEST 10                            AN ARGUMENT OF LOW MAGNITUDE 02310823
           IVTNUM = 10                                                  02320823
        AVD = DACOS(-1.0D-33)                                           02330823
           IF (AVD -  0.1570796326D+01) 20100, 10100, 40100             02340823
40100      IF (AVD -  0.1570796328D+01) 10100, 10100, 20100             02350823
10100      IVPASS = IVPASS + 1                                          02360823
           WRITE (NUVI, 80002) IVTNUM                                   02370823
           GO TO 0101                                                   02380823
20100      IVFAIL = IVFAIL + 1                                          02390823
           DVCORR =  1.5707963267948966192D+00                          02400823
           WRITE (NUVI, 80031) IVTNUM, AVD, DVCORR                      02410823
 0101      CONTINUE                                                     02420823
CT011*  TEST 11    COMPARISON OF DASIN AND DACOS FOR RIGHT RELATIONSHIP 02430823
           IVTNUM = 11                                                  02440823
        BVD = DASIN(DSQRT(3.0D0) / 3.0D0)                               02450823
        CVD = DACOS(DSQRT(3.0D0) / 3.0D0)                               02460823
        AVD = (BVD + CVD) * 2.0D0                                       02470823
           IF (AVD -  0.3141592652D+01) 20110, 10110, 40110             02480823
40110      IF (AVD -  0.3141592655D+01) 10110, 10110, 20110             02490823
10110      IVPASS = IVPASS + 1                                          02500823
           WRITE (NUVI, 80002) IVTNUM                                   02510823
           GO TO 0111                                                   02520823
20110      IVFAIL = IVFAIL + 1                                          02530823
           DVCORR =  3.1415926535897932384D+00                          02540823
           WRITE (NUVI, 80031) IVTNUM, AVD, DVCORR                      02550823
 0111      CONTINUE                                                     02560823
CT012*  TEST 12      COMPARISON OF DASIN AND DACOS TO TEST RELATIONSHIP 02570823
           IVTNUM = 12                                                  02580823
        AVD = (DASIN(+0.25D0) + DACOS(+0.25D0)) * 2.0D0                 02590823
           IF (AVD -  0.3141592652D+01) 20120, 10120, 40120             02600823
40120      IF (AVD -  0.3141592655D+01) 10120, 10120, 20120             02610823
10120      IVPASS = IVPASS + 1                                          02620823
           WRITE (NUVI, 80002) IVTNUM                                   02630823
           GO TO 0121                                                   02640823
20120      IVFAIL = IVFAIL + 1                                          02650823
           DVCORR =  3.1415926535897932384D+00                          02660823
           WRITE (NUVI, 80031) IVTNUM, AVD, DVCORR                      02670823
 0121      CONTINUE                                                     02680823
C*****                                                                  02690823
CBB** ********************** BBCSUM0  **********************************02700823
C**** WRITE OUT TEST SUMMARY                                            02710823
C****                                                                   02720823
      IVTOTN = IVPASS + IVFAIL + IVDELE + IVINSP                        02730823
      WRITE (I02, 90004)                                                02740823
      WRITE (I02, 90014)                                                02750823
      WRITE (I02, 90004)                                                02760823
      WRITE (I02, 90020) IVPASS                                         02770823
      WRITE (I02, 90022) IVFAIL                                         02780823
      WRITE (I02, 90024) IVDELE                                         02790823
      WRITE (I02, 90026) IVINSP                                         02800823
      WRITE (I02, 90028) IVTOTN, IVTOTL                                 02810823
CBE** ********************** BBCSUM0  **********************************02820823
CBB** ********************** BBCFOOT0 **********************************02830823
C**** WRITE OUT REPORT FOOTINGS                                         02840823
C****                                                                   02850823
      WRITE (I02,90016) ZPROG, ZPROG                                    02860823
      WRITE (I02,90018) ZPROJ, ZNAME, ZTAPE, ZTAPED                     02870823
      WRITE (I02,90019)                                                 02880823
CBE** ********************** BBCFOOT0 **********************************02890823
CBB** ********************** BBCFMT0A **********************************02900823
C**** FORMATS FOR TEST DETAIL LINES                                     02910823
C****                                                                   02920823
80000 FORMAT (" ",2X,I3,4X,"DELETED",32X,A31)                           02930823
80002 FORMAT (" ",2X,I3,4X," PASS  ",32X,A31)                           02940823
80004 FORMAT (" ",2X,I3,4X,"INSPECT",32X,A31)                           02950823
80008 FORMAT (" ",2X,I3,4X," FAIL  ",32X,A31)                           02960823
80010 FORMAT (" ",2X,I3,4X," FAIL  ",/," ",15X,"COMPUTED= " ,           02970823
     1I6,/," ",15X,"CORRECT=  " ,I6)                                    02980823
80012 FORMAT (" ",2X,I3,4X," FAIL  ",/," ",16X,"COMPUTED= " ,           02990823
     1E12.5,/," ",16X,"CORRECT=  " ,E12.5)                              03000823
80018 FORMAT (" ",2X,I3,4X," FAIL  ",/," ",16X,"COMPUTED= " ,           03010823
     1A21,/," ",16X,"CORRECT=  " ,A21)                                  03020823
80020 FORMAT (" ",16X,"COMPUTED= " ,A21,1X,A31)                         03030823
80022 FORMAT (" ",16X,"CORRECT=  " ,A21,1X,A31)                         03040823
80024 FORMAT (" ",16X,"COMPUTED= " ,I6,16X,A31)                         03050823
80026 FORMAT (" ",16X,"CORRECT=  " ,I6,16X,A31)                         03060823
80028 FORMAT (" ",16X,"COMPUTED= " ,E12.5,10X,A31)                      03070823
80030 FORMAT (" ",16X,"CORRECT=  " ,E12.5,10X,A31)                      03080823
80050 FORMAT (" ",48X,A31)                                              03090823
CBE** ********************** BBCFMT0A **********************************03100823
CBB** ********************** BBCFMAT1 **********************************03110823
C**** FORMATS FOR TEST DETAIL LINES - FULL LANGUAGE                     03120823
C****                                                                   03130823
80031 FORMAT (" ",2X,I3,4X," FAIL  ",/," ",16X,"COMPUTED= " ,           03140823
     1D17.10,/," ",16X,"CORRECT=  " ,D17.10)                            03150823
80033 FORMAT (" ",16X,"COMPUTED= " ,D17.10,10X,A31)                     03160823
80035 FORMAT (" ",16X,"CORRECT=  " ,D17.10,10X,A31)                     03170823
80037 FORMAT (" ",16X,"COMPUTED= " ,"(",E12.5,", ",E12.5,")",6X,A31)    03180823
80039 FORMAT (" ",16X,"CORRECT=  " ,"(",E12.5,", ",E12.5,")",6X,A31)    03190823
80041 FORMAT (" ",16X,"COMPUTED= " ,"(",F12.5,", ",F12.5,")",6X,A31)    03200823
80043 FORMAT (" ",16X,"CORRECT=  " ,"(",F12.5,", ",F12.5,")",6X,A31)    03210823
80045 FORMAT (" ",2X,I3,4X," FAIL  ",/," ",16X,"COMPUTED= " ,           03220823
     1"(",F12.5,", ",F12.5,")"/," ",16X,"CORRECT=  " ,                  03230823
     2"(",F12.5,", ",F12.5,")")                                         03240823
CBE** ********************** BBCFMAT1 **********************************03250823
CBB** ********************** BBCFMT0B **********************************03260823
C**** FORMAT STATEMENTS FOR PAGE HEADERS                                03270823
C****                                                                   03280823
90002 FORMAT ("1")                                                      03290823
90004 FORMAT (" ")                                                      03300823
90006 FORMAT (" ",20X,"NATIONAL INSTITUTE OF STANDARDS AND TECHNOLOGY" )03310823
90007 FORMAT (" ",19X,"FORTRAN COMPILER VALIDATION SYSTEM" )            03320823
90008 FORMAT (" ",21X,A13,A17)                                          03330823
90009 FORMAT (" ",/," *",A5,"BEGIN*",12X,"TEST RESULTS - " ,A5,/)       03340823
90010 FORMAT (" ",8X,"TEST DATE*TIME= " ,A17,"  -  COMPILER= " ,A20)    03350823
90013 FORMAT (" "," TEST   ","PASS/FAIL " ,6X,"DISPLAYED RESULTS" ,     03360823
     1       7X,"REMARKS",24X)                                          03370823
90014 FORMAT (" ","----------------------------------------------" ,    03380823
     1        "---------------------------------" )                     03390823
90015 FORMAT (" ",48X,"THIS PROGRAM HAS " ,I3," TESTS",/)               03400823
C****                                                                   03410823
C**** FORMAT STATEMENTS FOR REPORT FOOTINGS                             03420823
C****                                                                   03430823
90016 FORMAT (" ",/," *",A5,"END*",14X,"END OF TEST - " ,A5,/)          03440823
90018 FORMAT (" ",A13,13X,A20,"   *   ",A10,"/",                        03450823
     1        A13)                                                      03460823
90019 FORMAT (" ","FOR OFFICIAL USE ONLY     " ,35X,"COPYRIGHT  1982" ) 03470823
C****                                                                   03480823
C**** FORMAT STATEMENTS FOR RUN SUMMARY                                 03490823
C****                                                                   03500823
90020 FORMAT (" ",21X,I5," TESTS PASSED" )                              03510823
90022 FORMAT (" ",21X,I5," TESTS FAILED" )                              03520823
90024 FORMAT (" ",21X,I5," TESTS DELETED" )                             03530823
90026 FORMAT (" ",21X,I5," TESTS REQUIRE INSPECTION" )                  03540823
90028 FORMAT (" ",21X,I5," OF ",I3," TESTS EXECUTED" )                  03550823
CBE** ********************** BBCFMT0B **********************************03560823
C*****                                                                  03570823
C*****    END OF TEST SEGMENT 194                                       03580823
      STOP                                                              03590823
      END                                                               03600823

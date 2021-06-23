      PROGRAM FM914

C***********************************************************************00010914
C*****   FM914                                                          00020914
C*****                       INQU1 - (430)                              00030914
C*****                                                                  00040914
C***********************************************************************00050914
C*****  GENERAL PURPOSE                                         ANS REF 00060914
C*****    TEST INQUIRE BY UNIT ON SEQUENTIAL, FORMATTED FILES   12.10.3 00070914
C*****                                                                  00080914
C*****    THE TESTS IN THIS UNIT ARE ONLY PERFORMED ON A                00090914
C*****    UNIT THAT IS CONNECTED FOR SEQUENTIAL, FORMATTED ACCESS       00100914
C*****    (ANS REF. 12.2.4.1 AND 12.9.5.2)                              00110914
C*****    THIS TEST PERFORMS AN EXPLICIT OPEN, AND PERFORMS             00120914
C*****    A CLOSE WITH STATUS='DELETE' AT THE END OF THE SEGMENT.       00130914
C***********************************************************************00140914
CBB** ********************** BBCCOMNT **********************************00150914
C****                                                                   00160914
C****            1978 FORTRAN COMPILER VALIDATION SYSTEM                00170914
C****                          VERSION 2.1                              00180914
C****                                                                   00190914
C****                                                                   00200914
C****           SUGGESTIONS AND COMMENTS SHOULD BE FORWARDED TO         00210914
C****          NATIONAL INSTITUTE OF STANDARDS AND TECHNOLOGY           00220914
C****               SOFTWARE STANDARDS VALIDATION GROUP                 00230914
C****                      BUILDING 225  RM A266                        00240914
C****                     GAITHERSBURG, MD  20899                       00250914
C****                                                                   00260914
C****                                                                   00270914
C****                                                                   00280914
CBE** ********************** BBCCOMNT **********************************00290914
        LOGICAL AVB, BVB                                                00300914
        CHARACTER*10 B10VK, C10VK, E11VK*11, F10VK, H10VK               00310914
CBB** ********************** BBCINITA **********************************00320914
C**** SPECIFICATION STATEMENTS                                          00330914
C****                                                                   00340914
      CHARACTER ZVERS*13, ZVERSD*17, ZDATE*17, ZPROG*5, ZCOMPL*20,      00350914
     1          ZNAME*20, ZTAPE*10, ZPROJ*13, REMRKS*31, ZTAPED*13      00360914
CBE** ********************** BBCINITA **********************************00370914
CBB** ********************** BBCINITB **********************************00380914
C**** INITIALIZE SECTION                                                00390914
      DATA  ZVERS,                  ZVERSD,             ZDATE           00400914
     1      /'VERSION 2.1  ',  '93/10/21*21.02.00',  '*NO DATE*TIME'/   00410914
      DATA       ZCOMPL,             ZNAME,             ZTAPE           00420914
     1      /'*NONE SPECIFIED*', '*NO COMPANY NAME*', '*NO TAPE*'/      00430914
      DATA       ZPROJ,           ZTAPED,         ZPROG                 00440914
     1      /'*NO PROJECT*',   '*NO TAPE DATE',  'XXXXX'/               00450914
      DATA   REMRKS /'                               '/                 00460914
C**** THE FOLLOWING 9 COMMENT LINES (CZ01, CZ02, ...) CAN BE REPLACED   00470914
C**** FOR IDENTIFYING THE TEST ENVIRONMENT                              00480914
C****                                                                   00490914
CZ01  ZVERS  = 'VERSION OF THE COMPILER VALIDATION SYSTEM'              00500914
CZ02  ZVERSD = 'CREATION DATE/TIME OF THE COMPILER VALIDATION SYSTEM'   00510914
CZ03  ZPROG  = 'PROGRAM NAME'                                           00520914
CZ04  ZDATE  = 'DATE OF TEST'                                           00530914
CZ05  ZCOMPL = 'COMPILER IDENTIFICATION'                                00540914
CZ06  ZPROJ  = 'PROJECT NUMBER/IDENTIFICATION'                          00550914
CZ07  ZNAME  = 'NAME OF USER'                                           00560914
CZ08  ZTAPE  = 'TAPE OWNER/ID'                                          00570914
CZ09  ZTAPED = 'DATE TAPE COPIED'                                       00580914
C                                                                       00590914
      IVPASS = 0                                                        00600914
      IVFAIL = 0                                                        00610914
      IVDELE = 0                                                        00620914
      IVINSP = 0                                                        00630914
      IVTOTL = 0                                                        00640914
      IVTOTN = 0                                                        00650914
      ICZERO = 0                                                        00660914
C                                                                       00670914
C     I01 CONTAINS THE LOGICAL UNIT NUMBER FOR THE CARD READER.         00680914
      I01 = 05                                                          00690914
C     I02 CONTAINS THE LOGICAL UNIT NUMBER FOR THE PRINTER.             00700914
      I02 = 06                                                          00710914
C                                                                       00720914
CX010   REPLACED BY FEXEC X-010 CONTROL CARD (CARD-READER UNIT NUMBER). 00730914
C     THE CX010 CARD IS FOR OVERRIDING THE PROGRAM DEFAULT I01 = 5      00740914
CX011   REPLACED BY FEXEC X-011 CONTROL CARD.  CX011 IS FOR SYSTEMS     00750914
C     REQUIRING ADDITIONAL STATEMENTS FOR FILES ASSOCIATED WITH CX010.  00760914
C                                                                       00770914
CX020   REPLACED BY FEXEC X-020 CONTROL CARD (PRINTER UNIT NUMBER).     00780914
C     THE CX020 CARD IS FOR OVERRIDING THE PROGRAM DEFAULT I02= 6       00790914
CX021   REPLACED BY FEXEC X-021 CONTROL CARD.  CX021 IS FOR SYSTEMS     00800914
C     REQUIRING ADDITIONAL STATEMENTS FOR FILES ASSOCIATED WITH CX020.  00810914
C                                                                       00820914
CBE** ********************** BBCINITB **********************************00830914
C*****                                                                  00840914
C     I08 CONTAINS THE UNIT NUMBER FOR A SEQUENTIAL FORMATTED FILE.     00850914
      I08 = 918                                                         00860914
CX080   REPLACED BY FEXEC X-080 CONTROL CARD (SEQ. FILE UNIT NUMBER).   00870914
C     SPECIFYING I08 = NN OVERRIDES THE DEFAULT I08 = 14.               00880914
C*****                                                                  00890914
C*****    THE FOLLOWING STATEMENT MUST BE CHANGED IF                    00900914
C*****    THE UNIT GIVEN IS NOT CAPABLE OF BEING OPENED AS A            00910914
C*****    SEQUENTIAL, FORMATTED FILE.                                   00920914
C*****                                                                  00930914
      NUVI = I02                                                        00940914
      IMVI = I08                                                        00950914
      ZPROG = 'FM914'                                                   00960914
      IVTOTL = 1                                                        00970914
CBB** ********************** BBCHED0A **********************************00980914
C****                                                                   00990914
C**** WRITE REPORT TITLE                                                01000914
C****                                                                   01010914
      WRITE (I02, 90002)                                                01020914
      WRITE (I02, 90006)                                                01030914
      WRITE (I02, 90007)                                                01040914
      WRITE (I02, 90008)  ZVERS, ZVERSD                                 01050914
      WRITE (I02, 90009)  ZPROG, ZPROG                                  01060914
      WRITE (I02, 90010)  ZDATE, ZCOMPL                                 01070914
CBE** ********************** BBCHED0A **********************************01080914
C*****                                                                  01090914
        WRITE(NUVI,43000)                                               01100914
43000   FORMAT(" ", / " INQU1 - (430) INQUIRE BY UNIT" //               01110914
     1         " SEQUENTIAL FORMATTED FILE, CONNECTED BY OPEN" //       01120914
     2         " ANS REF. - 12.10.3" )                                  01130914
CBB** ********************** BBCHED0B **********************************01140914
C**** WRITE DETAIL REPORT HEADERS                                       01150914
C****                                                                   01160914
      WRITE (I02,90004)                                                 01170914
      WRITE (I02,90004)                                                 01180914
      WRITE (I02,90013)                                                 01190914
      WRITE (I02,90014)                                                 01200914
      WRITE (I02,90015) IVTOTL                                          01210914
CBE** ********************** BBCHED0B **********************************01220914
C*****                                                                  01230914
C*****    OPEN FILE                                                     01240914
C*****                                                                  01250914
        OPEN(UNIT=IMVI, ACCESS='SEQUENTIAL', FORM='FORMATTED',          01260914
     1       BLANK='NULL')                                              01270914
C*****                                                                  01280914
CT001*  TEST 1 - FIRST INQUIRE (AFTER OPEN)                             01290914
           IVTNUM = 1                                                   01300914
        INQUIRE(UNIT=IMVI, EXIST=AVB, OPENED=BVB, NUMBER=JVI,           01310914
     1          ACCESS=B10VK, SEQUENTIAL=C10VK, FORM=E11VK,             01320914
     2          FORMATTED=F10VK, BLANK=H10VK, ERR=20011, IOSTAT=KVI)    01330914
        IF (KVI .NE. 0) GO TO 20010                                     01340914
        IF (.NOT. AVB) GO TO 20010                                      01350914
        IF (.NOT. BVB) GO TO 20010                                      01360914
        IF (JVI .NE. IMVI) GO TO 20010                                  01370914
        IF (B10VK .NE. 'SEQUENTIAL') GO TO 20010                        01380914
        IF (C10VK .NE. 'YES') GO TO 20010                               01390914
        IF (E11VK .NE. 'FORMATTED') GO TO 20010                         01400914
        IF (F10VK .NE. 'YES' ) GO TO 20010                              01410914
        IF (H10VK .NE. 'NULL') GO TO 20010                              01420914
           WRITE (NUVI, 80002) IVTNUM                                   01430914
           IVPASS = IVPASS + 1                                          01440914
           GO TO 0011                                                   01450914
20011      CONTINUE                                                     01460914
           WRITE (NUVI, 20021) IVTNUM                                   01470914
20021      FORMAT (" ",2X,I3,4X," FAIL",12X,                            01480914
     1     "ERROR IN EXECUTION OF INQUIRE STATEMENT (ERR=)" /)          01490914
           GO TO 20012                                                  01500914
20010      CONTINUE                                                     01510914
           WRITE (NUVI, 20020) IVTNUM                                   01520914
20020      FORMAT(" ",2X,I3,4X," FAIL",12X,                             01530914
     1     "ERROR IN AN INQUIRE SPECIFIER" /)                           01540914
20012      CONTINUE                                                     01550914
           IVFAIL = IVFAIL + 1                                          01560914
           WRITE (NUVI, 20030) KVI,AVB,BVB,JVI,B10VK,C10VK,E11VK,       01570914
     1                         F10VK,H10VK                              01580914
20030      FORMAT (" ",16X,"COMPUTED: " ,"IOSTAT=",I1,", EXIST=",L1,    01590914
     1             " ,OPENED=",L1,", NUMBER=",I4,","/                   01600914
     2             " ",26X,"ACCESS=",A10,", SEQUENTIAL=" ,A3,", FORM=", 01610914
     3             A9,","/" ",26X,"FORMATTED=" ,A3,", BLANK=",A4)       01620914
           WRITE (NUVI, 20040) IMVI                                     01630914
20040      FORMAT (" ",16X,"CORRECT:  " ,"IOSTAT=0, EXIST=T, " ,        01640914
     1             "OPENED=T, NUMBER=" ,I4,","/                         01650914
     2             " ",26X,"ACCESS=SEQUENTIAL, SEQUENTIAL=YES, FORM=" , 01660914
     3             "FORMATTED," /" ",26X,"FORMATTED=YES, BLANK=NULL" )  01670914
 0011   CONTINUE                                                        01680914
C*****                                                                  01690914
        REWIND IMVI                                                     01700914
        CLOSE(UNIT=IMVI, STATUS='DELETE')                               01710914
CBB** ********************** BBCSUM0  **********************************01720914
C**** WRITE OUT TEST SUMMARY                                            01730914
C****                                                                   01740914
      IVTOTN = IVPASS + IVFAIL + IVDELE + IVINSP                        01750914
      WRITE (I02, 90004)                                                01760914
      WRITE (I02, 90014)                                                01770914
      WRITE (I02, 90004)                                                01780914
      WRITE (I02, 90020) IVPASS                                         01790914
      WRITE (I02, 90022) IVFAIL                                         01800914
      WRITE (I02, 90024) IVDELE                                         01810914
      WRITE (I02, 90026) IVINSP                                         01820914
      WRITE (I02, 90028) IVTOTN, IVTOTL                                 01830914
CBE** ********************** BBCSUM0  **********************************01840914
CBB** ********************** BBCFOOT0 **********************************01850914
C**** WRITE OUT REPORT FOOTINGS                                         01860914
C****                                                                   01870914
      WRITE (I02,90016) ZPROG, ZPROG                                    01880914
      WRITE (I02,90018) ZPROJ, ZNAME, ZTAPE, ZTAPED                     01890914
      WRITE (I02,90019)                                                 01900914
CBE** ********************** BBCFOOT0 **********************************01910914
CBB** ********************** BBCFMT0A **********************************01920914
C**** FORMATS FOR TEST DETAIL LINES                                     01930914
C****                                                                   01940914
80000 FORMAT (" ",2X,I3,4X,"DELETED",32X,A31)                           01950914
80002 FORMAT (" ",2X,I3,4X," PASS  ",32X,A31)                           01960914
80004 FORMAT (" ",2X,I3,4X,"INSPECT",32X,A31)                           01970914
80008 FORMAT (" ",2X,I3,4X," FAIL  ",32X,A31)                           01980914
80010 FORMAT (" ",2X,I3,4X," FAIL  ",/," ",15X,"COMPUTED= " ,           01990914
     1I6,/," ",15X,"CORRECT=  " ,I6)                                    02000914
80012 FORMAT (" ",2X,I3,4X," FAIL  ",/," ",16X,"COMPUTED= " ,           02010914
     1E12.5,/," ",16X,"CORRECT=  " ,E12.5)                              02020914
80018 FORMAT (" ",2X,I3,4X," FAIL  ",/," ",16X,"COMPUTED= " ,           02030914
     1A21,/," ",16X,"CORRECT=  " ,A21)                                  02040914
80020 FORMAT (" ",16X,"COMPUTED= " ,A21,1X,A31)                         02050914
80022 FORMAT (" ",16X,"CORRECT=  " ,A21,1X,A31)                         02060914
80024 FORMAT (" ",16X,"COMPUTED= " ,I6,16X,A31)                         02070914
80026 FORMAT (" ",16X,"CORRECT=  " ,I6,16X,A31)                         02080914
80028 FORMAT (" ",16X,"COMPUTED= " ,E12.5,10X,A31)                      02090914
80030 FORMAT (" ",16X,"CORRECT=  " ,E12.5,10X,A31)                      02100914
80050 FORMAT (" ",48X,A31)                                              02110914
CBE** ********************** BBCFMT0A **********************************02120914
CBB** ********************** BBCFMAT1 **********************************02130914
C**** FORMATS FOR TEST DETAIL LINES - FULL LANGUAGE                     02140914
C****                                                                   02150914
80031 FORMAT (" ",2X,I3,4X," FAIL  ",/," ",16X,"COMPUTED= " ,           02160914
     1D17.10,/," ",16X,"CORRECT=  " ,D17.10)                            02170914
80033 FORMAT (" ",16X,"COMPUTED= " ,D17.10,10X,A31)                     02180914
80035 FORMAT (" ",16X,"CORRECT=  " ,D17.10,10X,A31)                     02190914
80037 FORMAT (" ",16X,"COMPUTED= " ,"(",E12.5,", ",E12.5,")",6X,A31)    02200914
80039 FORMAT (" ",16X,"CORRECT=  " ,"(",E12.5,", ",E12.5,")",6X,A31)    02210914
80041 FORMAT (" ",16X,"COMPUTED= " ,"(",F12.5,", ",F12.5,")",6X,A31)    02220914
80043 FORMAT (" ",16X,"CORRECT=  " ,"(",F12.5,", ",F12.5,")",6X,A31)    02230914
80045 FORMAT (" ",2X,I3,4X," FAIL  ",/," ",16X,"COMPUTED= " ,           02240914
     1"(",F12.5,", ",F12.5,")"/," ",16X,"CORRECT=  " ,                  02250914
     2"(",F12.5,", ",F12.5,")")                                         02260914
CBE** ********************** BBCFMAT1 **********************************02270914
CBB** ********************** BBCFMT0B **********************************02280914
C**** FORMAT STATEMENTS FOR PAGE HEADERS                                02290914
C****                                                                   02300914
90002 FORMAT ("1")                                                      02310914
90004 FORMAT (" ")                                                      02320914
90006 FORMAT (" ",20X,"NATIONAL INSTITUTE OF STANDARDS AND TECHNOLOGY" )02330914
90007 FORMAT (" ",19X,"FORTRAN COMPILER VALIDATION SYSTEM" )            02340914
90008 FORMAT (" ",21X,A13,A17)                                          02350914
90009 FORMAT (" ",/," *",A5,"BEGIN*",12X,"TEST RESULTS - " ,A5,/)       02360914
90010 FORMAT (" ",8X,"TEST DATE*TIME= " ,A17,"  -  COMPILER= " ,A20)    02370914
90013 FORMAT (" "," TEST   ","PASS/FAIL " ,6X,"DISPLAYED RESULTS" ,     02380914
     1       7X,"REMARKS",24X)                                          02390914
90014 FORMAT (" ","----------------------------------------------" ,    02400914
     1        "---------------------------------" )                     02410914
90015 FORMAT (" ",48X,"THIS PROGRAM HAS " ,I3," TESTS",/)               02420914
C****                                                                   02430914
C**** FORMAT STATEMENTS FOR REPORT FOOTINGS                             02440914
C****                                                                   02450914
90016 FORMAT (" ",/," *",A5,"END*",14X,"END OF TEST - " ,A5,/)          02460914
90018 FORMAT (" ",A13,13X,A20,"   *   ",A10,"/",                        02470914
     1        A13)                                                      02480914
90019 FORMAT (" ","FOR OFFICIAL USE ONLY     " ,35X,"COPYRIGHT  1982" ) 02490914
C****                                                                   02500914
C**** FORMAT STATEMENTS FOR RUN SUMMARY                                 02510914
C****                                                                   02520914
90020 FORMAT (" ",21X,I5," TESTS PASSED" )                              02530914
90022 FORMAT (" ",21X,I5," TESTS FAILED" )                              02540914
90024 FORMAT (" ",21X,I5," TESTS DELETED" )                             02550914
90026 FORMAT (" ",21X,I5," TESTS REQUIRE INSPECTION" )                  02560914
90028 FORMAT (" ",21X,I5," OF ",I3," TESTS EXECUTED" )                  02570914
CBE** ********************** BBCFMT0B **********************************02580914
C*****                                                                  02590914
C*****    END OF TEST SEGMENT 914                                       02600914
        STOP                                                            02610914
        END                                                             02620914

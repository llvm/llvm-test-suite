; ModuleID = 'L'
source_filename = "L"

@literal = private constant [5 x i8] c"main\00", align 1
@_debugInfo = external global i8
@_sourceCodeObj = external global i8
@literal.1 = private constant [24 x i8] c"_sub_split_main__split0\00", align 1

; Function Attrs: noinline nounwind optnone sspreq willreturn
define i64 @_sub_split_main__split0(ptr %_context, ptr noalias %counter, ptr %jumpAddr) #0 {
_sub_split_main__split0_entry:
  %RC = alloca i64, align 8
  %RCLineNumber_l6 = alloca i32, align 4
  %Result_l9_c15 = alloca i8, align 1
  %Result_l7_c8 = alloca i8, align 1
  br label %_sub_split_main__split0_first

_sub_split_main__split0_first:                    ; preds = %_sub_split_main__split0_entry
  store i64 0, ptr %RC, align 8
  store i32 0, ptr %RCLineNumber_l6, align 4
  %value_l7_c8 = load i32, ptr %counter, align 4
  %result2.i = icmp sge i32 %value_l7_c8, 8
  %0 = zext i1 %result2.i to i8
  store i8 %0, ptr %Result_l7_c8, align 1
  %_l7_c8 = load i8, ptr %Result_l7_c8, align 1
  %1 = icmp ne i8 %_l7_c8, 0
  br i1 %1, label %l7_if_then, label %l7_if_else

l4_chain_unwind:                                  ; No predecessors!
  %RC1 = phi i64
  %RCLineNumber = phi i32
  store i64 %RC1, ptr %RC, align 8
  store i32 %RCLineNumber, ptr %RCLineNumber_l6, align 4
  br label %_sub_split_main__split0_rcc_unwind_top

l7_if_then:                                       ; preds = %_sub_split_main__split0_first
  store ptr blockaddress(@main, %loopCtrlExit), ptr %jumpAddr, align 8
  br label %_sub_split_main__split0_return

l7_if_else:                                       ; preds = %_sub_split_main__split0_first
  %value_l9_c15 = load i32, ptr %counter, align 4
  %result2.i3 = icmp sge i32 %value_l9_c15, 4
  %2 = zext i1 %result2.i3 to i8
  store i8 %2, ptr %Result_l9_c15, align 1
  %_l9_c15 = load i8, ptr %Result_l9_c15, align 1
  %3 = icmp ne i8 %_l9_c15, 0
  br i1 %3, label %l9_if_then, label %l9_if_exit

l9_if_then:                                       ; preds = %l7_if_else
  store ptr blockaddress(@main, %loopCtrlExit3), ptr %jumpAddr, align 8
  br label %_sub_split_main__split0_return

l9_if_exit:                                       ; preds = %l7_if_else
  br label %l7_if_exit

l7_if_exit:                                       ; preds = %l9_if_exit
  br label %_sub_split_main__split0_return

_sub_split_main__split0_return:                   ; preds = %l7_if_exit, %l9_if_then, %l7_if_then, %_sub_split_main__split0_rcc_unwind_top
  %RCValue = load i64, ptr %RC, align 8
  ret i64 %RCValue

_sub_split_main__split0_rcc_unwind_top:           ; preds = %l4_chain_unwind
  %RCLineNumber_l62 = load i32, ptr %RCLineNumber_l6, align 4
  %RC_l6_i1 = load i64, ptr %RC, align 8
  %rc_l6_i2 = call i64 @llangStackTracePushVoid(ptr %_context, i32 %RCLineNumber_l62, i64 %RC_l6_i1, ptr @literal.1, ptr @_debugInfo, ptr @_sourceCodeObj)
  br label %_sub_split_main__split0_return
}

; Function Attrs: noinline nounwind optnone sspreq willreturn
define i64 @main() #0 {
main_entry:
  %Result = alloca i64, align 8
  %_context = alloca i64, align 8
  %RC.i = alloca i64, align 8
  %RC = alloca i64, align 8
  %RCLineNumber_l1 = alloca i32, align 4
  %x_l2 = alloca i8, align 1
  %counter_l3 = alloca i32, align 4
  %tmpSmallValue_l3_c18 = alloca i64, align 8
  %jmpAddr_l6 = alloca ptr, align 8
  %Result_l4_c9 = alloca i8, align 1
  br label %main_first

main_first:                                       ; preds = %main_entry
  store i64 0, ptr %RC, align 8
  store i32 0, ptr %RCLineNumber_l1, align 4
  store i8 0, ptr %x_l2, align 1
  %rc_l3 = call i64 @llangTestProduce(ptr %tmpSmallValue_l3_c18, i64 5)
  %asInt64 = load i64, ptr %tmpSmallValue_l3_c18, align 8
  %asIntN = trunc i64 %asInt64 to i32
  store i32 %asIntN, ptr %counter_l3, align 4
  br label %l4_while_head

l0_chain_unwind:                                  ; preds = %l5_rcc_ok, %l4_while_body
  %RC1 = phi i64 [ %RCValue.i, %l4_while_body ], [ %rc_l6_i3, %l5_rcc_ok ]
  %RCLineNumber = phi i32 [ 5, %l4_while_body ], [ 6, %l5_rcc_ok ]
  store i64 %RC1, ptr %RC, align 8
  store i32 %RCLineNumber, ptr %RCLineNumber_l1, align 4
  br label %main_rcc_unwind_top

l4_while_body:                                    ; preds = %l4_while_head
  call void @llvm.lifetime.start.p0(i64 8, ptr %RC.i)
  store i64 0, ptr %RC.i, align 8
  %thiss_value.i = load i32, ptr %counter_l3, align 4
  %0 = call { i32, i1 } @llvm.sadd.with.overflow.i32(i32 %thiss_value.i, i32 1)
  %value.i = extractvalue { i32, i1 } %0, 0
  %errorBit.i = extractvalue { i32, i1 } %0, 1
  %extErrBit.i = zext i1 %errorBit.i to i64
  store i64 %extErrBit.i, ptr %RC.i, align 8
  store i32 %value.i, ptr %counter_l3, align 4
  %RCValue.i = load i64, ptr %RC.i, align 8
  call void @llvm.lifetime.end.p0(i64 8, ptr %RC.i)
  %rcCmp_l5_i1 = icmp ne i64 %RCValue.i, 0
  br i1 %rcCmp_l5_i1, label %l0_chain_unwind, label %l5_rcc_ok, !prof !0

l5_rcc_ok:                                        ; preds = %l4_while_body
  store ptr blockaddress(@main, %l6_regularExit), ptr %jmpAddr_l6, align 8
  %rc_l6_i3 = call i64 @_sub_split_main__split0(ptr %_context, ptr %counter_l3, ptr %jmpAddr_l6)
  %rcCmp_l6_i4 = icmp ne i64 %rc_l6_i3, 0
  br i1 %rcCmp_l6_i4, label %l0_chain_unwind, label %l6_rcc_ok, !prof !0

loopCtrlExit:                                     ; preds = %l6_rcc_ok
  br label %l4_while_exit_ok

loopCtrlExit3:                                    ; preds = %l6_rcc_ok
  br label %l4_while_head

l6_regularExit:                                   ; preds = %l6_rcc_ok
  %value_l13_c18 = load i32, ptr %counter_l3, align 4
  %asInt644 = zext i32 %value_l13_c18 to i64
  %rc_l13 = call i64 @llangTestConsume(i64 %asInt644)
  br label %l4_while_head

l6_rcc_ok:                                        ; preds = %l5_rcc_ok
  %jumpAddrLoaded = load ptr, ptr %jmpAddr_l6, align 8
  indirectbr ptr %jumpAddrLoaded, [label %l6_regularExit, label %loopCtrlExit, label %loopCtrlExit3]

l4_while_head:                                    ; preds = %l6_regularExit, %loopCtrlExit3, %main_first
  %value_l4_c9 = load i32, ptr %counter_l3, align 4
  %result2.i = icmp slt i32 %value_l4_c9, 10
  %1 = zext i1 %result2.i to i8
  store i8 %1, ptr %Result_l4_c9, align 1
  %_l4_c9 = load i8, ptr %Result_l4_c9, align 1
  %2 = icmp ne i8 %_l4_c9, 0
  br i1 %2, label %l4_while_body, label %l4_while_exit_ok

l4_while_exit_ok:                                 ; preds = %l4_while_head, %loopCtrlExit
  store i32 1, ptr %Result, align 4
  br label %main_return

main_return:                                      ; preds = %l4_while_exit_ok, %main_rcc_unwind_top
  %RCValue = load i64, ptr %RC, align 8
  ret i64 %RCValue

main_rcc_unwind_top:                              ; preds = %l0_chain_unwind
  %RCLineNumber_l12 = load i32, ptr %RCLineNumber_l1, align 4
  %RC_l1_i1 = load i64, ptr %RC, align 8
  %rc_l1_i2 = call i64 @llangStackTracePushVoid(ptr %_context, i32 %RCLineNumber_l12, i64 %RC_l1_i1, ptr @literal, ptr @_debugInfo, ptr @_sourceCodeObj)
  br label %main_return
}

; Function Attrs: nounwind sspreq willreturn
declare i64 @llangStackTracePushVoid(ptr, i32 signext, i64 signext, ptr, ptr, ptr) #1

; Function Attrs: nounwind sspreq willreturn
declare i64 @llangTestProduce(ptr, i64) #1

; Function Attrs: nounwind sspreq willreturn
declare i64 @"Int32~_operator_inc~Void"(ptr) #1

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare { i32, i1 } @llvm.sadd.with.overflow.i32(i32, i32) #2

; Function Attrs: nounwind sspreq willreturn
declare i64 @"Int32~_operator_ge~Int32~Bool"(ptr, i32 signext, i32 signext) #1

; Function Attrs: nounwind sspreq willreturn
declare i64 @llangTestConsume(i64) #1

; Function Attrs: nounwind sspreq willreturn
declare i64 @"Int32~_operator_lt~Int32~Bool"(ptr, i32 signext, i32 signext) #1

; Function Attrs: nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.start.p0(i64 immarg, ptr captures(none)) #3

; Function Attrs: nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.end.p0(i64 immarg, ptr captures(none)) #3

attributes #0 = { noinline nounwind optnone sspreq willreturn "frame-pointer"="all" }
attributes #1 = { nounwind sspreq willreturn "frame-pointer"="all" }
attributes #2 = { nocallback nofree nosync nounwind speculatable willreturn memory(none) }
attributes #3 = { nocallback nofree nosync nounwind willreturn memory(argmem: readwrite) }

!0 = !{!"branch_weights", i32 4, i32 64}

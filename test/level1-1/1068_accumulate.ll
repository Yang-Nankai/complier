define i32 @main() {
B15:
  %t17 = alloca i32, align 4
  %t16 = alloca i32, align 4
  store i32 0, i32* %t17, align 4
  store i32 0, i32* %t16, align 4
  br label %B18
B18:                               	; preds = %B15, %B19
  %t4 = load i32, i32* %t16, align 4
  %t5 = icmp slt i32 %t4, 21
  br i1 %t5, label %B19, label %B23
B19:                               	; preds = %B18
  %t7 = load i32, i32* %t17, align 4
  %t8 = load i32, i32* %t16, align 4
  %t9 = add i32 %t7, %t8
  store i32 %t9, i32* %t17, align 4
  %t11 = load i32, i32* %t16, align 4
  %t12 = add i32 %t11, 1
  store i32 %t12, i32* %t16, align 4
  br label %B18
B23:                               	; preds = %B18
  br label %B20
B20:                               	; preds = %B23
  %t13 = load i32, i32* %t17, align 4
  %t14 = call i32 @putint(i32 %t13)
  ret i32 0
}
declare i32 @putint(i32)

define i32 @main() {
B25:
  %t27 = alloca i32, align 4
  %t26 = alloca i32, align 4
  store i32 56, i32* %t26, align 4
  store i32 4, i32* %t27, align 4
  %t5 = load i32, i32* %t26, align 4
  %t6 = sub i32 0, 4
  %t7 = sub i32 %t5, %t6
  %t8 = load i32, i32* %t27, align 4
  %t9 = add i32 %t7, %t8
  store i32 %t9, i32* %t26, align 4
  %t10 = load i32, i32* %t26, align 4
  %t31 = icmp ne i32 %t10, 0
  %t11 = xor i1 %t31, true
  %t12 = xor i1 %t11, true
  %t13 = xor i1 %t12, true
  %t32 = zext i1 %t13 to i32
  %t14 = sub i32 0, %t32
  %t22 = icmp ne i32 %t14, 0
  br i1 %t22, label %B28, label %B34
B28:                               	; preds = %B25
  %t16 = sub i32 0, 1
  %t17 = sub i32 0, %t16
  %t18 = sub i32 0, %t17
  store i32 %t18, i32* %t26, align 4
  br label %B30
B34:                               	; preds = %B25
  br label %B29
B30:                               	; preds = %B28, %B29
  %t23 = load i32, i32* %t26, align 4
  %t24 = call i32 @putint(i32 %t23)
  ret i32 0
B29:                               	; preds = %B34
  %t20 = load i32, i32* %t27, align 4
  %t21 = add i32 0, %t20
  store i32 %t21, i32* %t26, align 4
  br label %B30
}
declare i32 @putint(i32)

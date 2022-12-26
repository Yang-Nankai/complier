define i32 @main() {
B44:
  %t49 = alloca i32, align 4
  %t48 = alloca i32, align 4
  %t47 = alloca i32, align 4
  %t46 = alloca i32, align 4
  %t45 = alloca i32, align 4
  store i32 5, i32* %t45, align 4
  store i32 5, i32* %t46, align 4
  store i32 1, i32* %t47, align 4
  %t9 = sub i32 0, 2
  store i32 %t9, i32* %t48, align 4
  store i32 2, i32* %t49, align 4
  %t11 = load i32, i32* %t48, align 4
  %t12 = mul i32 %t11, 1
  %t13 = sdiv i32 %t12, 2
  %t14 = icmp slt i32 %t13, 0
  br i1 %t14, label %B50, label %B55
B50:                               	; preds = %B44, %B56
  %t25 = load i32, i32* %t49, align 4
  %t26 = call i32 @putint(i32 %t25)
  br label %B51
B55:                               	; preds = %B44
  br label %B52
B51:                               	; preds = %B50, %B59, %B62
  %t27 = load i32, i32* %t48, align 4
  %t28 = srem i32 %t27, 2
  %t29 = add i32 %t28, 67
  %t30 = icmp slt i32 %t29, 0
  br i1 %t30, label %B63, label %B68
B52:                               	; preds = %B55
  %t15 = load i32, i32* %t45, align 4
  %t16 = load i32, i32* %t46, align 4
  %t17 = sub i32 %t15, %t16
  %t18 = icmp ne i32 %t17, 0
  br i1 %t18, label %B56, label %B59
B63:                               	; preds = %B51, %B69
  store i32 4, i32* %t49, align 4
  %t42 = load i32, i32* %t49, align 4
  %t43 = call i32 @putint(i32 %t42)
  br label %B64
B68:                               	; preds = %B51
  br label %B65
B56:                               	; preds = %B52
  %t19 = load i32, i32* %t47, align 4
  %t20 = add i32 %t19, 3
  %t21 = srem i32 %t20, 2
  %t22 = icmp ne i32 %t21, 0
  br i1 %t22, label %B50, label %B62
B59:                               	; preds = %B52
  br label %B51
B64:                               	; preds = %B63, %B72, %B75
  ret i32 0
B65:                               	; preds = %B68
  %t31 = load i32, i32* %t45, align 4
  %t32 = load i32, i32* %t46, align 4
  %t33 = sub i32 %t31, %t32
  %t34 = icmp ne i32 %t33, 0
  br i1 %t34, label %B69, label %B72
B62:                               	; preds = %B56
  br label %B51
B69:                               	; preds = %B65
  %t35 = load i32, i32* %t47, align 4
  %t36 = add i32 %t35, 2
  %t37 = srem i32 %t36, 2
  %t38 = icmp ne i32 %t37, 0
  br i1 %t38, label %B63, label %B75
B72:                               	; preds = %B65
  br label %B64
B75:                               	; preds = %B69
  br label %B64
}
declare i32 @putint(i32)

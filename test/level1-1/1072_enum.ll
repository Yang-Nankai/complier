define i32 @main() {
B42:
  %t46 = alloca i32, align 4
  %t45 = alloca i32, align 4
  %t44 = alloca i32, align 4
  %t43 = alloca i32, align 4
  store i32 0, i32* %t43, align 4
  store i32 0, i32* %t44, align 4
  store i32 0, i32* %t45, align 4
  br label %B47
B47:                               	; preds = %B42, %B55
  %t7 = load i32, i32* %t43, align 4
  %t8 = icmp slt i32 %t7, 21
  br i1 %t8, label %B48, label %B52
B48:                               	; preds = %B47
  br label %B53
B52:                               	; preds = %B47
  br label %B49
B53:                               	; preds = %B48, %B60
  %t9 = load i32, i32* %t44, align 4
  %t10 = load i32, i32* %t43, align 4
  %t11 = sub i32 101, %t10
  %t12 = icmp slt i32 %t9, %t11
  br i1 %t12, label %B54, label %B58
B49:                               	; preds = %B52
  ret i32 0
B54:                               	; preds = %B53
  %t14 = load i32, i32* %t43, align 4
  %t15 = sub i32 100, %t14
  %t16 = load i32, i32* %t44, align 4
  %t17 = sub i32 %t15, %t16
  store i32 %t17, i32* %t45, align 4
  %t18 = load i32, i32* %t43, align 4
  %t19 = mul i32 5, %t18
  %t20 = load i32, i32* %t44, align 4
  %t21 = mul i32 1, %t20
  %t22 = add i32 %t19, %t21
  %t23 = load i32, i32* %t45, align 4
  %t24 = sdiv i32 %t23, 2
  %t25 = add i32 %t22, %t24
  %t26 = icmp eq i32 %t25, 100
  br i1 %t26, label %B59, label %B63
B58:                               	; preds = %B53
  br label %B55
B59:                               	; preds = %B54
  %t27 = load i32, i32* %t43, align 4
  %t28 = call i32 @putint(i32 %t27)
  %t29 = load i32, i32* %t44, align 4
  %t30 = call i32 @putint(i32 %t29)
  %t31 = load i32, i32* %t45, align 4
  %t32 = call i32 @putint(i32 %t31)
  store i32 10, i32* %t46, align 4
  %t34 = load i32, i32* %t46, align 4
  %t35 = call i32 @putch(i32 %t34)
  br label %B60
B63:                               	; preds = %B54
  br label %B60
B55:                               	; preds = %B58
  %t40 = load i32, i32* %t43, align 4
  %t41 = add i32 %t40, 1
  store i32 %t41, i32* %t43, align 4
  br label %B47
B60:                               	; preds = %B59, %B63
  %t37 = load i32, i32* %t44, align 4
  %t38 = add i32 %t37, 1
  store i32 %t38, i32* %t44, align 4
  br label %B53
}
declare i32 @putint(i32)
declare i32 @putch(i32)

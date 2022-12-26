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
  %t11 = load i32, i32* %t48, align 4
  %t12 = mul i32 %t11, 1
  %t13 = sdiv i32 %t12, 2
  %t14 = load i32, i32* %t45, align 4
  %t15 = load i32, i32* %t46, align 4
  %t16 = sub i32 %t14, %t15
  %t17 = add i32 %t13, %t16
  %t18 = load i32, i32* %t47, align 4
  %t19 = add i32 %t18, 3
  %t20 = sub i32 0, %t19
  %t21 = srem i32 %t20, 2
  %t22 = sub i32 %t17, %t21
  store i32 %t22, i32* %t49, align 4
  %t23 = load i32, i32* %t49, align 4
  %t24 = call i32 @putint(i32 %t23)
  %t26 = load i32, i32* %t48, align 4
  %t27 = srem i32 %t26, 2
  %t28 = add i32 %t27, 67
  %t29 = load i32, i32* %t45, align 4
  %t30 = load i32, i32* %t46, align 4
  %t31 = sub i32 %t29, %t30
  %t32 = sub i32 0, %t31
  %t33 = add i32 %t28, %t32
  %t34 = load i32, i32* %t47, align 4
  %t35 = add i32 %t34, 2
  %t36 = srem i32 %t35, 2
  %t37 = sub i32 0, %t36
  %t38 = sub i32 %t33, %t37
  store i32 %t38, i32* %t49, align 4
  %t40 = load i32, i32* %t49, align 4
  %t41 = add i32 %t40, 3
  store i32 %t41, i32* %t49, align 4
  %t42 = load i32, i32* %t49, align 4
  %t43 = call i32 @putint(i32 %t42)
  ret i32 0
}
declare i32 @putint(i32)

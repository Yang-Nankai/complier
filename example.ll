define i32 @main() {
B39:
  %t42 = alloca float, align 4
  %t41 = alloca i32, align 4
  %t40 = alloca float, align 4
  store float 10, float* %t40, align 4
  store i32 0, i32* %t41, align 4
  %t3 = load float, float* %t40, align 4
  %t4 = load i32, i32* %t41, align 4
  %t6 = sitofp i32 %t4 to float
  %t5 = fadd float %t3, %t6
  store float %t5, float* %t42, align 4
  %t9 = load float, float* %t40, align 4
  %t10 = load i32, i32* %t41, align 4
  %t12 = sitofp i32 %t10 to float
  %t11 = fmul float %t9, %t12
  store float %t11, float* %t42, align 4
  %t13 = load i32, i32* %t41, align 4
  %t45 = icmp ne i32 %t13, 0
  %t14 = xor i1 %t45, true
  %t15 = icmp ne i1 %t14, 0
  br i1 %t15, label %B43, label %B47
B43:                               	; preds = %B39
  br label %B44
B47:                               	; preds = %B39
  br label %B44
B44:                               	; preds = %B43, %B47
  %t16 = load float, float* %t40, align 4
  %t52 = fcmp one float %t16, 0
  %t17 = xor i1 %t52, true
  %t38 = icmp ne i1 %t17, 0
  br i1 %t38, label %B49, label %B54
B49:                               	; preds = %B44
  br label %B51
B54:                               	; preds = %B44
  br label %B50
B51:                               	; preds = %B49, %B58
  ret i32 0
B50:                               	; preds = %B54
  %t18 = load float, float* %t40, align 4
  %t20 = sitofp i32 1 to float
  %t19 = fcmp ogt float %t18, %t20
  br i1 %t19, label %B56, label %B61
B56:                               	; preds = %B50
  br label %B58
B61:                               	; preds = %B50
  br label %B57
B58:                               	; preds = %B56, %B64
  br label %B51
B57:                               	; preds = %B61
  %t21 = load float, float* %t40, align 4
  %t22 = fcmp olt float %t21, 1.2
  br i1 %t22, label %B62, label %B67
B62:                               	; preds = %B57
  br label %B64
B67:                               	; preds = %B57
  br label %B63
B64:                               	; preds = %B62, %B70
  br label %B58
B63:                               	; preds = %B67
  %t23 = load float, float* %t40, align 4
  %t24 = load i32, i32* %t41, align 4
  %t26 = sitofp i32 %t24 to float
  %t25 = fcmp oge float %t23, %t26
  br i1 %t25, label %B68, label %B73
B68:                               	; preds = %B63
  br label %B70
B73:                               	; preds = %B63
  br label %B69
B70:                               	; preds = %B68, %B76
  br label %B64
B69:                               	; preds = %B73
  %t27 = load float, float* %t40, align 4
  %t28 = load i32, i32* %t41, align 4
  %t30 = sitofp i32 %t28 to float
  %t29 = fcmp ole float %t27, %t30
  br i1 %t29, label %B74, label %B79
B74:                               	; preds = %B69
  br label %B76
B79:                               	; preds = %B69
  br label %B75
B76:                               	; preds = %B74, %B82
  br label %B70
B75:                               	; preds = %B79
  %t31 = load float, float* %t40, align 4
  %t32 = fcmp oeq float %t31, 2.1
  br i1 %t32, label %B80, label %B85
B80:                               	; preds = %B75
  br label %B82
B85:                               	; preds = %B75
  br label %B81
B82:                               	; preds = %B80, %B88
  br label %B76
B81:                               	; preds = %B85
  %t33 = load float, float* %t40, align 4
  %t36 = fcmp one float %t33, 0
  br i1 %t36, label %B89, label %B91
B89:                               	; preds = %B81
  %t34 = load i32, i32* %t41, align 4
  %t37 = icmp ne i32 %t34, 0
  br i1 %t37, label %B86, label %B94
B91:                               	; preds = %B81
  br label %B87
B86:                               	; preds = %B89
  br label %B88
B94:                               	; preds = %B89
  br label %B87
B87:                               	; preds = %B91, %B94
  br label %B88
B88:                               	; preds = %B86, %B87
  br label %B82
}

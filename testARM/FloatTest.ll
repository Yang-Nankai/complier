define dso_local i32 @main() #0 {
  %2 = alloca float, align 4
  %3 = alloca i32, align 4
  %4 = alloca float, align 4
  store float 1.000000e+01, float* %2, align 4
  store i32 0, i32* %3, align 4
  %5 = load float, float* %2, align 4
  %6 = load i32, i32* %3, align 4
  %7 = sitofp i32 %6 to float
  %8 = fadd float %5, %7
  store float %8, float* %4, align 4
  %9 = load float, float* %2, align 4
  %10 = load i32, i32* %3, align 4
  %11 = sitofp i32 %10 to float
  %12 = fmul float %9, %11
  store float %12, float* %4, align 4
  %13 = load i32, i32* %3, align 4
  %14 = icmp ne i32 %13, 0
  br i1 %14, label %16, label %15

15:                                               ; preds = %0
  br label %16

16:                                               ; preds = %15, %0
  %17 = load float, float* %2, align 4
  %18 = fcmp une float %17, 0.000000e+00
  br i1 %18, label %20, label %19

19:                                               ; preds = %16
  br label %60

20:                                               ; preds = %16
  %21 = load float, float* %2, align 4
  %22 = fcmp ogt float %21, 1.000000e+00
  br i1 %22, label %23, label %24

23:                                               ; preds = %20
  br label %59

24:                                               ; preds = %20
  %25 = load float, float* %2, align 4
  %26 = fpext float %25 to double
  %27 = fcmp olt double %26, 1.200000e+00
  br i1 %27, label %28, label %29

28:                                               ; preds = %24
  br label %58

29:                                               ; preds = %24
  %30 = load float, float* %2, align 4
  %31 = load i32, i32* %3, align 4
  %32 = sitofp i32 %31 to float
  %33 = fcmp oge float %30, %32
  br i1 %33, label %34, label %35

34:                                               ; preds = %29
  br label %57

35:                                               ; preds = %29
  %36 = load float, float* %2, align 4
  %37 = load i32, i32* %3, align 4
  %38 = sitofp i32 %37 to float
  %39 = fcmp ole float %36, %38
  br i1 %39, label %40, label %41

40:                                               ; preds = %35
  br label %56

41:                                               ; preds = %35
  %42 = load float, float* %2, align 4
  %43 = fpext float %42 to double
  %44 = fcmp oeq double %43, 2.100000e+00
  br i1 %44, label %45, label %46

45:                                               ; preds = %41
  br label %55

46:                                               ; preds = %41
  %47 = load float, float* %2, align 4
  %48 = fcmp une float %47, 0.000000e+00
  br i1 %48, label %49, label %53

49:                                               ; preds = %46
  %50 = load i32, i32* %3, align 4
  %51 = icmp ne i32 %50, 0
  br i1 %51, label %52, label %53

52:                                               ; preds = %49
  br label %54

53:                                               ; preds = %49, %46
  br label %54

54:                                               ; preds = %53, %52
  br label %55

55:                                               ; preds = %54, %45
  br label %56

56:                                               ; preds = %55, %40
  br label %57

57:                                               ; preds = %56, %34
  br label %58

58:                                               ; preds = %57, %28
  br label %59

59:                                               ; preds = %58, %23
  br label %60

60:                                               ; preds = %59, %19
  ret i32 0
}

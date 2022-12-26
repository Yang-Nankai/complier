; ModuleID = 'FloatTest1.c'
source_filename = "FloatTest1.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca float, align 4
  %3 = alloca i32, align 4
  %4 = alloca float, align 4
  store i32 0, i32* %1, align 4
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
  br label %58

20:                                               ; preds = %16
  %21 = load float, float* %2, align 4
  %22 = fcmp ogt float %21, 1.000000e+00
  br i1 %22, label %23, label %24

23:                                               ; preds = %20
  br label %57

24:                                               ; preds = %20
  %25 = load float, float* %2, align 4
  %26 = fcmp olt float %25, 0x3FF3333340000000
  br i1 %26, label %27, label %28

27:                                               ; preds = %24
  br label %56

28:                                               ; preds = %24
  %29 = load float, float* %2, align 4
  %30 = load i32, i32* %3, align 4
  %31 = sitofp i32 %30 to float
  %32 = fcmp oge float %29, %31
  br i1 %32, label %33, label %34

33:                                               ; preds = %28
  br label %55

34:                                               ; preds = %28
  %35 = load float, float* %2, align 4
  %36 = load i32, i32* %3, align 4
  %37 = sitofp i32 %36 to float
  %38 = fcmp ole float %35, %37
  br i1 %38, label %39, label %40

39:                                               ; preds = %34
  br label %54

40:                                               ; preds = %34
  %41 = load float, float* %2, align 4
  %42 = fcmp oeq float %41, 0x4000CCCCC0000000
  br i1 %42, label %43, label %44

43:                                               ; preds = %40
  br label %53

44:                                               ; preds = %40
  %45 = load float, float* %2, align 4
  %46 = fcmp une float %45, 0.000000e+00
  br i1 %46, label %47, label %51

47:                                               ; preds = %44
  %48 = load i32, i32* %3, align 4
  %49 = icmp ne i32 %48, 0
  br i1 %49, label %50, label %51

50:                                               ; preds = %47
  br label %52

51:                                               ; preds = %47, %44
  br label %52

52:                                               ; preds = %51, %50
  br label %53

53:                                               ; preds = %52, %43
  br label %54

54:                                               ; preds = %53, %39
  br label %55

55:                                               ; preds = %54, %33
  br label %56

56:                                               ; preds = %55, %27
  br label %57

57:                                               ; preds = %56, %23
  br label %58

58:                                               ; preds = %57, %19
  ret i32 0
}

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 10.0.0-4ubuntu1 "}

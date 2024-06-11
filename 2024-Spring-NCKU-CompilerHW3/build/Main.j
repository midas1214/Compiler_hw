.source Main.j
.class public Main
.super java/lang/Object
.method public static calculate_pi(I)F
.limit stack 100
.limit locals 100
	ldc 3.000000
	fstore 1
	ldc 2.000000
	fstore 2
	iconst_1
	istore 3
L_for_start1:
	ldc 1
	istore 4
L_for_cond_start1:
	iload 4
	iload 0
	if_icmplt L_les0
	iconst_0
	goto L_after_les0
L_les0:
	iconst_1
L_after_les0:
	ifeq L_after_for1
	goto L_for_body_start1
L_for_update_start1:
	iload 4
	ldc 1
	iadd
	istore 4
	goto L_for_cond_start1
L_for_body_start1:
	ldc 4
	i2f
	fload 2
	iload 4
	i2f
	fmul
	fload 2
	iload 4
	i2f
	fmul
	ldc 1.000000
	fadd
	fmul
	fload 2
	iload 4
	i2f
	fmul
	fload 2
	fadd
	fmul
	fdiv
	fstore 5
	iload 3
	ifeq L_after_if0
	fload 5
	fload 1
	swap
	fadd
	fstore 1
	iconst_0
	istore 3
	goto L_after_else0
L_after_if0:
L_before_else0:
	fload 5
	fload 1
	swap
	fsub
	fstore 1
	iconst_1
	istore 3
L_after_else0:
	goto L_for_update_start1
L_after_for1:
	fload 1
	freturn
.end method
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 100
	ldc 100
	istore 1
	iload 1
	invokestatic Main/calculate_pi(I)F
	fstore 2
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "Approximation of Pi after ";
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 1
	invokevirtual java/io/PrintStream/print(I)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc " terms: ";
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	fload 2
	invokevirtual java/io/PrintStream/print(F)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	invokevirtual java/io/PrintStream/println()V
	return
.end method

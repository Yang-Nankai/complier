//define some global values

#ifndef __DEFINE_H__
#define __DEFINE_H__


//operator
#define OP_ADD 50
#define OP_SUB 51
#define OP_MUL 52
#define OP_DIV 53
#define OP_MOD 54
#define OP_AND 55
#define OP_OR 56
#define OP_EQUAL 57
#define OP_NOTEQUAL 58
#define OP_LESS 59
#define OP_LESSEQ 60
#define OP_GREATER 61
#define OP_GREATEREQ 62
#define OP_NOT 63

//define expr kind
#define EXPR_NORMAL 100
#define EXPR_INITVALUELIST 101
#define EXPR_IMPLICTCASTEXPR 102
#define EXPR_UNARY 103
#define EXPR_IMPLICTCASTFLOATEXPR 104

//define stmt kind
#define STMT_IF 110
#define STMT_IFELSE 111
#define STMT_WHILE 112
#define STMT_COMPUND 113
#define STMT_RETURN 114

//symbol type
#define SYM_CONSTANT 200
#define SYM_VARIABLE 201
#define SYM_TEMPORARY 202
//define identifier symbol type
#define ID_GLOBAL 203
#define ID_PARAM 204
#define ID_LOCAL 205

//define type
#define TYPE_INT 301
#define TYPE_FLOAT 302
#define TYPE_VOID 303
#define TYPE_FUNC 304
#define TYPE_ARRAY 305
#define TYPE_STRING 306
#define TYPE_PTR 307




#endif
grammar Algebric;

entryPoint: expression;

expression:	LITERAL 									#LiteralPrimaryExpression
			| 'SQRT' '(' expression ')' 				#SqrtPrimaryExpression
			| '(' expression ')'  						#ParenthesizedPrimaryExpression
			| (PLUS | MINUS) expression					#UnaryExpression
			| expression (MULT | DIV | EXP) expression	#BinaryExpressionP1
			| expression (PLUS | MINUS) expression		#BinaryExpressionP2;
				
PLUS:	'+';

MINUS:	'-';

MULT:	'*';

DIV:	'/';

EXP:	'^';

LITERAL:	NUMBER | VAR;

NUMBER:	[0-9]+('.'[0-9]+)?;

VAR:	[a-zA-Z];

WHITESPACE:	' '+ -> skip;
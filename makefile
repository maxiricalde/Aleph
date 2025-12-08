aleph: aleph.y aleph.l
	bison -d -t aleph.y -Wcounterexamples
	flex aleph.l
	gcc -Iinclude aleph.tab.c lex.yy.c aleph.c sym_table.c src/tData.c src/TAD_TCad.c -o aleph
	

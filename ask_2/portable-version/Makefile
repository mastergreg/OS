all:	tree-portable.patch proc-common-portable.patch	
tree-portable.patch: tree.c
	-diff ../forktree/tree.c tree.c > tree-portable.patch;
proc-common-portable.patch: proc-common.c
	-diff ../forktree/proc-common.c proc-common.c > proc-common-portable.patch;
clean:
	rm *.patch

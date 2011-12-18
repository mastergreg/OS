all:	tree-c-portable.patch proc-common-c-portable.patch tree-h-portable.patch proc-common-h-portable.patch	
tree-c-portable.patch: tree.c
	-diff ../forktree/tree.c tree.c > tree-c-portable.patch;
tree-h-portable.patch: tree.h
	-diff ../forktree/tree.h tree.h > tree-h-portable.patch;
proc-common-c-portable.patch: proc-common.c
	-diff ../forktree/proc-common.c proc-common.c > proc-common-c-portable.patch;
proc-common-h-portable.patch: proc-common.h
	-diff ../forktree/proc-common.h proc-common.h > proc-common-h-portable.patch;
clean:
	rm *.patch

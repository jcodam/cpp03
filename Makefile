
all:

f:
	@$(MAKE) -C ex00 fclean --no-print-directory
	@$(MAKE) -C ex01 fclean --no-print-directory
	@$(MAKE) -C ex02 fclean --no-print-directory
	@$(MAKE) -C ex03 fclean --no-print-directory
	
0:
	$(MAKE) -C ex00
0r:
	$(MAKE) -C ex00 r
0re:
	$(MAKE) -C ex00 re
0f:
	$(MAKE) -C ex00 fclean

1:
	$(MAKE) -C ex01
1r:
	$(MAKE) -C ex01 r
1re:
	$(MAKE) -C ex01 re
1f:
	$(MAKE) -C ex01 fclean

2:
	$(MAKE) -C ex02
2r:
	$(MAKE) -C ex02 r
2re:
	$(MAKE) -C ex02 re
2f:
	$(MAKE) -C ex02 fclean
3:
	$(MAKE) -C ex03
3r:
	$(MAKE) -C ex03 r
3re:
	$(MAKE) -C ex03 re
3f:
	$(MAKE) -C ex03 fclean
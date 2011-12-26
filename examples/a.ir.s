	.section	__TEXT,__text,regular,pure_instructions
	.align	4, 0x90
_main:                                  ## @main
Leh_func_begin0:
## BB#0:                                ## %entry
	movq	$15, -8(%rsp)
	ret
Leh_func_end0:

	.section	__TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame0:
Lsection_eh_frame0:
Leh_frame_common0:
Lset0 = Leh_frame_common_end0-Leh_frame_common_begin0 ## Length of Common Information Entry
	.long	Lset0
Leh_frame_common_begin0:
	.long	0                       ## CIE Identifier Tag
	.byte	1                       ## DW_CIE_VERSION
	.asciz	 "zR"                   ## CIE Augmentation
	.byte	1                       ## CIE Code Alignment Factor
	.byte	120                     ## CIE Data Alignment Factor
	.byte	16                      ## CIE Return Address Column
	.byte	1                       ## Augmentation Size
	.byte	16                      ## FDE Encoding = pcrel
	.byte	12                      ## DW_CFA_def_cfa
	.byte	7                       ## Register
	.byte	8                       ## Offset
	.byte	144                     ## DW_CFA_offset + Reg (16)
	.byte	1                       ## Offset
	.align	3
Leh_frame_common_end0:
_main.eh = 0
	.no_dead_strip	_main.eh


.subsections_via_symbols

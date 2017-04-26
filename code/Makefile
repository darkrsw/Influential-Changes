LGRIND_COCCI = lgrind -i -d ./lgrindef -l cocci -v keywords
LGRIND_C = lgrind -i -l C -v code_keywords

all: clean usb_submit_urb.lg

%.lg: %.c
	$(LGRIND_C) $< > $@ 

%.lg: %.cocci
	$(LGRIND_COCCI) $< > $@ 

clean :
	rm -f *.lg

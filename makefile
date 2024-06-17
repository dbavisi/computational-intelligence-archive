BUILD_DIR = .build

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -O3 -fms-extensions -I.

INCLUDE_C_ARTIFACTS = ""
define INCLUDE_C
$(BUILD_DIR)/include/c/lib$(1).o: include/c/$(1)/$(1).c
	@mkdir -p $$(dir $$@)
	$$(CC) $$(CFLAGS) $$< -o $$@
	$(eval INCLUDE_C_ARTIFACTS += $(BUILD_DIR)/include/c/lib$(1).o)
endef

STRUCTURE_C_ARTIFACTS = ""
define STRUCTURE_C
$(BUILD_DIR)/structure/c/lib$(1)_$(2).o: structure/$(1)/implementation/$(2)/c/$(1).c
	@mkdir -p $$(dir $$@)
	$$(CC) $$(CFLAGS) $$< -o $$@
	$(eval STRUCTURE_C_ARTIFACTS += $(BUILD_DIR)/structure/c/lib$(1)_$(2).o)
endef

for file in $(wildcard include/c/*/*.c)
do
	$(eval inc := $(basename $( notdir $(file))))
	$(eval $(call INCLUDE_C,$(inc)))
done

for file in $(wildcard structure/*/implementation/*/c/*.c)
do
	$(eval str := $(subst /, ,$(file)))
	$(eval struct := $(word 2,$(str)))
	$(eval impl := $(word 4,$(str)))
	$(eval $(call STRUCTURE_C,$(struct),$(impl)))
done

all: $(INCLUDE_C_ARTIFACTS) $(STRUCTURE_C_ARTIFACTS)

clean:
	rm -rf $(BUILD_DIR)

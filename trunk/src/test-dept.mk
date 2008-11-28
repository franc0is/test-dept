# Copyright 2008 Mattias Norrby
#
# This file is part of Test Dept..
#
# Test Dept. is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Test Dept. is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Test Dept..  If not, see <http://www.gnu.org/licenses/>.
#
# As a special exception, you may use this file as part of a free
# testing framework without restriction.  Specifically, if other files
# include this makefile for contructing test-cases this file does not
# by itself cause the resulting executable to be covered by the GNU
# General Public License.  This exception does not however invalidate
# any other reasons why the executable file might be covered by the
# GNU General Public License.

TEST_DEPT_EXEC_ARCH?=$(shell uname -m)
SYMBOLS_TO_ASM=$(TEST_DEPT_RUNTIME_PREFIX)sym2asm_$(TEST_DEPT_EXEC_ARCH).awk

%_using_proxies.o:	%.o
	$(TEST_DEPT_BIN_PATH)/repoint_sut $< $@

%_proxies.s: %.o
	$(TEST_DEPT_BIN_PATH)/build_asm_proxies $(SYMBOLS_TO_ASM) $< >$@

%_test_main.c: %_test.o
	 $(TEST_DEPT_BIN_PATH)/build_main_from_symbols $< >$@

%_test:	%_test_main.o %_test.o %_using_proxies.o %_proxies.s
	$(CC) -o $@ $^

ifneq (,$(TEST_DEPT_INCLUDE_PATH))
TEST_DEPT_MAKEFILE_INCLUDE_PATH=$(TEST_DEPT_INCLUDE_PATH)/
endif
include $(TEST_DEPT_MAKEFILE_INCLUDE_PATH)test-dept-definitions.mk

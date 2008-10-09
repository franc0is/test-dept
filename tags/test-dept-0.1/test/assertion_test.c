/* Copyright 2008 Mattias Norrby
 * 
 * This file is part of Test Dept..
 * 
 * Test Dept. is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Test Dept. is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Test Dept..  If not, see <http://www.gnu.org/licenses/>.
 */
#include <test_dept.h>
#include <values.h>

void test_function_without_assertions() {
}

void test_function_with_assertions() {
  assert_true(1);
}

void test_assert_equals_with_integers() {
  assert_equals(0, 0);
  assert_equals(1, 1);
  assert_equals(-1, -1);
  assert_equals(MAXINT, MAXINT);
  assert_equals(-MAXINT, -MAXINT);
}

void test_assert_equals_with_floats() {
  assert_equals(0.0, 0.0);
  assert_equals(1.0, 1.0);
  assert_equals(-1.1, -1.1);
  assert_equals(-1.191919191, -1.191919191);
}

void test_for_loop_around_assertion() {
  int i, j;
  for (i =j = 0; i < 1000; i++, j++)
    assert_equals(i, j);
}

void test_assert_not_equals_with_integers() {
  assert_not_equals(1, 0);
  assert_not_equals(1, -1);
  assert_not_equals(MAXINT, -MAXINT);
}

void test_assert_false() {
  assert_false(0);
}

void test_assert_equals_int() {
  int three = 3;
  assert_equals_int(3, three);
  char* pointer = (char *) &three;
  char* foo = pointer;
  assert_equals_int(pointer, foo);
  assert_equals_hex(pointer, foo);
}

void test_assert_equals_char() {
  char three = '3';
  assert_equals_char('3', three);
}

void test_assert_equals_float() {
  float pi = 3.1f;
  assert_equals_float(3.1f, pi);
}

void test_assert_equals_double() {
  double pi = 3.1;
  assert_equals_float(3.1, pi);
}

void test_assert_equals_string() {
  char* front = "242";
  assert_equals_string("242", front);
  unsigned char* Front = "242";
  assert_equals_string("242", Front);
}

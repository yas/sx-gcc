// 2001-05-21 Benjamin Kosnik  <bkoz@redhat.com>

// Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
// USA.

// 27.8.1.4 Overridden virtual functions

#include <fstream>
#include <testsuite_hooks.h>

void test01()
{
  using namespace std;

  bool test __attribute__((unused)) = true;
  char buf[512];
  const char* strlit = "how to tell a story and other essays: mark twain";
  const size_t strlitsize = std::strlen(strlit);
  filebuf fbuf;
  fbuf.pubsetbuf(buf, 512);
  fbuf.open("tmp_setbuf2", ios_base::out);
  fbuf.sputn(strlit, strlitsize);
  VERIFY( std::strncmp(strlit, buf, strlitsize) == 0 );
}

int main() 
{
  test01();
  return 0;
}

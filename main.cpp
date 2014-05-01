//
//  main.cpp
//  OptionTest
//
//  Created by Axel Naumann on 4/27/14.
//  Copyright (c) 2014 self. All rights reserved.
//

#include "Options.h"

// two example functions
void takesOptions(OptionSet<SomeOptions_t> opt);
void takesDOptions(OptionSet<DerivedOptions_t> opt);

int main(int argc, const char * argv[])
{
   // works and should work.
   takesOptions(SomeOptions.Option1);
   takesOptions(SomeOptions.Option1 + SomeOptions.Option3);
   // shouldn't work.
   takesOptions(SomeOptions.Option1 + DerivedOptions.Option3);
   // shouldn't work.
   takesOptions(DerivedOptions.Option1D + DerivedOptions.Option3);
   // shouldn't work.
   takesOptions(DifferentOptions.Option1DD);

   // works and should work.
   takesDOptions(DerivedOptions.Option1D + DerivedOptions.Option3D);
   // works and should work.
   takesDOptions(DerivedOptions.Option1D + DerivedOptions.Option3);

   return 0;
}


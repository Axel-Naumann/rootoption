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
   takesOptions(SomeOptions.Option1 + SomeOptions.Option3);
   // works but should NOT work!
   takesOptions(SomeOptions.Option1 + DerivedOptions.Option3);
   // doesn't work and shouldn't work.
   takesOptions(DerivedOptions.Option1D + DerivedOptions.Option3);
   // doesn't work and shouldn't work.
   takesOptions(DifferentOptions.Option1DD);

   // works and should work.
   takesDOptions(DerivedOptions.Option1D + DerivedOptions.Option3D);
   // doesn't work but SHOULD work!
   takesDOptions(DerivedOptions.Option1D + SomeOptions.Option3);

   return 0;
}


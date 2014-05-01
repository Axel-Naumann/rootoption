//
//  main.cpp
//  OptionTest
//
//  Created by Axel Naumann on 4/27/14.
//  Copyright (c) 2014 self. All rights reserved.
//

#include "Options.h"

// two example functions
void draw1DHist(OptionSet<Hist1DOpt_t> opt);
void draw2DHist(OptionSet<Hist2DOpt_t> opt);

int main(int argc, const char * argv[])
{
   // works and should work.
   draw1DHist(Hist1DOpt.Same);
   draw1DHist(Hist1DOpt.Bar3D);
   draw1DHist(Hist1DOpt.ErrorT + Hist1DOpt.Same);
   // shouldn't work.
   draw1DHist(Hist2DOpt.Same);
   // shouldn't work.
   draw1DHist(Hist1DOpt.Bar + Hist2DOpt.Box);
   // shouldn't work.
   draw1DHist(Hist2DOpt.Box + Hist1DOpt.Arrow);

   // works and should work.
   draw2DHist(Hist2DOpt.Box + Hist2DOpt.Arrow);
   // works and should work.
   draw2DHist(Hist2DOpt.Arrow + Hist2DOpt.Same);
   // shouldn't work.
   draw2DHist(Hist1DOpt.Same);
   // shouldn't work.
   draw2DHist(Hist2DOpt.Box + Hist1DOpt.Same);
   return 0;
}


//
//  Options.h
//  OptionTest
//
//  Created by Axel Naumann on 4/27/14.
//  Copyright (c) 2014 self. All rights reserved.
//

#ifndef OptionTest_Options_h
#define OptionTest_Options_h

// An Option.
template <typename OPTIONGROUP>
struct Option {
   typedef Option<OPTIONGROUP> Option_t;
   Option(const char* val);
};

template <typename OPTIONGROUP>
Option<OPTIONGROUP> operator+(Option<OPTIONGROUP> one,
                              Option<OPTIONGROUP> two);

// ------- Actual Option Definitions, e.g. in ROOT/Histogram.hxx --------

// A set of generic histogram options
template <typename DERIVEDKIND>
struct HistOptBase_t {
   HistOptBase_t() {}
   typedef const Option<DERIVEDKIND> Option_t;

   Option_t Same       = "SAME"; //<- Superimpose on previous picture in the same pad.
   Option_t XAxisOnTop = "X+"; //<- The X-axis is drawn on the top side of the plot.
   Option_t Errors     = "E"; //<- Draw error bars.
};

// 1D histogram options
static const struct Hist1DOpt_t: public HistOptBase_t<Hist1DOpt_t> {
   Hist1DOpt_t() {}
   
   Option_t Bar    = "B"; //<- Bar chart option.
   Option_t Bar3D  = "BAR"; //<- Like option "B", but bars can be drawn with a 3D effect.
   Option_t ErrorT = "E1"; //<- Draw error bars with perpendicular lines at the edges.
} Hist1DOpt;

// A derived set of options; reuses SomeOptionsBase_t but cannot convert
// to SomeOptions_t
static const struct Hist2DOpt_t: public HistOptBase_t<Hist2DOpt_t> {
   Hist2DOpt_t() {}

   Option_t Box = "BOX"; //<- A box is drawn for each cell with surface proportional to the content's absolute value. A negative content is marked with a X.
   Option_t Arrow = "ARR"; //<- Arrow mode. Shows gradient between adjacent cells.
   Option_t ContourSurfaceColor = "CONT0"; //<- Draw a contour plot using surface colors to distinguish contours.
} Hist2DOpt;

#endif

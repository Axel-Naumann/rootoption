//
//  Options.h
//  OptionTest
//
//  Created by Axel Naumann on 4/27/14.
//  Copyright (c) 2014 self. All rights reserved.
//

#ifndef OptionTest_Options_h
#define OptionTest_Options_h

template <typename OPTIONKIND>
struct Option;

// A combination of Option-s.
template <typename OPTIONKIND>
struct OptionSet {
   typedef Option<OPTIONKIND> Option_t;
   OptionSet() = default;
   OptionSet(Option_t); // build from single option
};

// An Option.
template <typename OPTIONKIND>
struct Option {
   Option(const char* val);
};

// Combining options into an OptionSet.
// This doesn't work, see examples in main.cpp.
template <typename OPTIONKIND>
OptionSet<OPTIONKIND> operator+(const Option<OPTIONKIND>& one, const Option<OPTIONKIND>& two);


// A set of options
static const struct SomeOptions_t {
   SomeOptions_t() {}
   typedef Option<SomeOptions_t> Option_t;

   Option_t Option1 = "Option1";
   Option_t Option2 = "Option2";
   Option_t Option3 = "Option3";
} SomeOptions;

// A derived set of options
static const struct DerivedOptions_t: public SomeOptions_t {
   DerivedOptions_t() {}
   typedef Option<DerivedOptions_t> Option_t;

   Option_t Option1D = "Option1D";
   Option_t Option2D = "Option2D";
   Option_t Option3D = "Option3D";
} DerivedOptions;

// An unrelated set of options
static const struct DifferentOptions_t: public SomeOptions_t {
   DifferentOptions_t() {}
   typedef Option<DifferentOptions_t> Option_t;
   
   Option_t Option1DD = "Option1DD";
   Option_t Option2DD = "Option2DD";
   Option_t Option3DD = "Option3DD";
} DifferentOptions;

#endif

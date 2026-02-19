#pragma once

#include "HList.h"
#include "Monome.h"

class Polynome : public HList<Monome> {
	using HList<Monome>::head;
	using HList<Monome>::last;

};
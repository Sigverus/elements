/*=================================================================================================   Copyright (c) 2016 Joel de Guzman   Licensed under a Creative Commons Attribution-ShareAlike 4.0 International.   http://creativecommons.org/licenses/by-sa/4.0/=================================================================================================*/#if !defined(PHOTON_GUI_LIB_CONTEXT_APRIL_17_2016)#define PHOTON_GUI_LIB_CONTEXT_APRIL_17_2016#include <photon/support/point.hpp>#include <photon/support/rect.hpp>#include <photon/view.hpp>namespace photon{	////////////////////////////////////////////////////////////////////////////////////////////////	// Contexts	////////////////////////////////////////////////////////////////////////////////////////////////   class view;   class widget;   class canvas;   struct basic_context   {      basic_context(view& view_)       : _view(view_)      {}      basic_context(basic_context const&) = default;      basic_context& operator=(basic_context const&) = default;      photon::canvas       canvas() const;      view&                _view;   };	////////////////////////////////////////////////////////////////////////////////////////////////   struct context : basic_context   {      context(context const& rhs, rect bounds_)       : basic_context(rhs._view), widget(rhs.widget)       , parent(rhs.parent), bounds(bounds_)      {}      context(context const& parent_, widget* widget_, rect bounds_)       : basic_context(parent_._view), widget(widget_)       , parent(&parent_), bounds(bounds_)      {}      context(class view& view_, widget* widget_, rect bounds_)       : basic_context(view_), widget(widget_)       , parent(0), bounds(bounds_)      {}      context(context const&) = default;      context& operator=(context const&) = default;      widget*              widget;      context const*       parent;      rect                 bounds;   };}#endif
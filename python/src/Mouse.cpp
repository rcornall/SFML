////////////////////////////////////////////////////////////
//
// PySFML - Python binding for SFML (Simple and Fast Multimedia Library)
// Copyright (C) 2007, 2008 Rémi Koenig (remi.k2620@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#include <SFML/Window/Event.hpp>

#include <Python.h>
#include <structmember.h>

#include "Mouse.hpp"


typedef struct {
	PyObject_HEAD
} PySfMouse;



static PyMemberDef PySfMouse_members[] = {
	{NULL}  /* Sentinel */
};


static void
PySfMouse_dealloc(PySfMouse *self)
{
	self->ob_type->tp_free((PyObject*)self);
}

static PyObject *
PySfMouse_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	PySfMouse *self;

	self = (PySfMouse *)type->tp_alloc(type, 0);
	if (self != NULL)
	{
	}

	return (PyObject *)self;
}


static int
PySfMouse_init(PySfMouse *self, PyObject *args, PyObject *kwds)
{
	return 0;
}

static PyMethodDef PySfMouse_methods[] = {
	{NULL}  /* Sentinel */
};

PyTypeObject PySfMouseType = {
	PyObject_HEAD_INIT(NULL)
	0,						/*ob_size*/
	"Mouse",				/*tp_name*/
	sizeof(PySfMouse),		/*tp_basicsize*/
	0,						/*tp_itemsize*/
	(destructor)PySfMouse_dealloc, /*tp_dealloc*/
	0,						/*tp_print*/
	0,						/*tp_getattr*/
	0,						/*tp_setattr*/
	0,						/*tp_compare*/
	0,						/*tp_repr*/
	0,						/*tp_as_number*/
	0,						/*tp_as_sequence*/
	0,						/*tp_as_mapping*/
	0,						/*tp_hash */
	0,						/*tp_call*/
	0,						/*tp_str*/
	0,						/*tp_getattro*/
	0,						/*tp_setattro*/
	0,						/*tp_as_buffer*/
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
	"Definition of button codes for mouse events.", /* tp_doc */
	0,						/* tp_traverse */
	0,						/* tp_clear */
	0,						/* tp_richcompare */
	0,						/* tp_weaklistoffset */
	0,						/* tp_iter */
	0,						/* tp_iternext */
	PySfMouse_methods,		/* tp_methods */
	PySfMouse_members,		/* tp_members */
	0,						/* tp_getset */
	0,						/* tp_base */
	0,						/* tp_dict */
	0,						/* tp_descr_get */
	0,						/* tp_descr_set */
	0,						/* tp_dictoffset */
	(initproc)PySfMouse_init, /* tp_init */
	0,						/* tp_alloc */
	PySfMouse_new,			/* tp_new */
};

void PySfMouse_InitConst()
{
	PyObject *obj;
	obj = PyInt_FromLong(sf::Mouse::Left);
	PyDict_SetItemString(PySfMouseType.tp_dict, "Left", obj);
	Py_DECREF(obj);
	obj = PyInt_FromLong(sf::Mouse::Right);
	PyDict_SetItemString(PySfMouseType.tp_dict, "Right", obj);
	Py_DECREF(obj);
	obj = PyInt_FromLong(sf::Mouse::Middle);
	PyDict_SetItemString(PySfMouseType.tp_dict, "Middle", obj);
	Py_DECREF(obj);
	obj = PyInt_FromLong(sf::Mouse::XButton1);
	PyDict_SetItemString(PySfMouseType.tp_dict, "XButton1", obj);
	Py_DECREF(obj);
	obj = PyInt_FromLong(sf::Mouse::XButton2);
	PyDict_SetItemString(PySfMouseType.tp_dict, "XButton2", obj);
	Py_DECREF(obj);
}


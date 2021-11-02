#ifndef Py_INTERNAL_ABSTRACT_H
#define Py_INTERNAL_ABSTRACT_H
#ifdef __cplusplus
extern "C" {
#endif

#ifndef Py_BUILD_CORE
#  error "this header requires Py_BUILD_CORE define"
#endif

/* return called function */
struct PowerResult {
    PyObject *result;
    binaryfunc func;
};

// Fast inlined version of PyIndex_Check()
static inline int
_PyIndex_Check(PyObject *obj)
{
    PyNumberMethods *tp_as_number = Py_TYPE(obj)->tp_as_number;
    return (tp_as_number != NULL && tp_as_number->nb_index != NULL);
}

struct PowerResult _PyNumber_BinaryOp(PyObject *v, PyObject *w, const int op_slot,
                             const char *op_name);
PyObject *_PyNumber_InPlaceOp(PyObject *v, PyObject *w, const int iop_slot,
                              const int op_slot, const char *op_name);

#ifdef __cplusplus
}
#endif
#endif /* !Py_INTERNAL_ABSTRACT_H */

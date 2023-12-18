module;

#include <rtm/math.h>
#include <rtm/scalarf.h>
#include <rtm/scalard.h>
#include <rtm/qvvf.h>
#include <rtm/qvvd.h>
#include <rtm/vector4f.h>
#include <rtm/vector4d.h>
#include <rtm/matrix3x4f.h>
#include <rtm/matrix3x4d.h>
#include <rtm/matrix4x4f.h>
#include <rtm/matrix4x4d.h>
#include <rtm/quatf.h>
#include <rtm/quatd.h>

export module rtmcpp;

#pragma warning(push)
#pragma warning(disable: 5244) // '#include <meow>' in the purview of module 'std' appears erroneous.

#include "Matrix.hpp"
#include "MatrixOps.hpp"
#include "PackedVector.hpp"
#include "Quat.hpp"
#include "QuatOps.hpp"
#include "Transforms.hpp"
#include "Vector.hpp"
#include "VectorOps.hpp"
#include "Scalar.hpp"

#include "Conversion.hpp"

#pragma warning(pop)

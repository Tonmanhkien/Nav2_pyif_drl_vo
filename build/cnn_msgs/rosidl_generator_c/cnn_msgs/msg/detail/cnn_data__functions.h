// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from cnn_msgs:msg/CNNData.idl
// generated code does not contain a copyright notice

#ifndef CNN_MSGS__MSG__DETAIL__CNN_DATA__FUNCTIONS_H_
#define CNN_MSGS__MSG__DETAIL__CNN_DATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "cnn_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "cnn_msgs/msg/detail/cnn_data__struct.h"

/// Initialize msg/CNNData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cnn_msgs__msg__CNNData
 * )) before or use
 * cnn_msgs__msg__CNNData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cnn_msgs
bool
cnn_msgs__msg__CNNData__init(cnn_msgs__msg__CNNData * msg);

/// Finalize msg/CNNData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cnn_msgs
void
cnn_msgs__msg__CNNData__fini(cnn_msgs__msg__CNNData * msg);

/// Create msg/CNNData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cnn_msgs__msg__CNNData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cnn_msgs
cnn_msgs__msg__CNNData *
cnn_msgs__msg__CNNData__create();

/// Destroy msg/CNNData message.
/**
 * It calls
 * cnn_msgs__msg__CNNData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cnn_msgs
void
cnn_msgs__msg__CNNData__destroy(cnn_msgs__msg__CNNData * msg);

/// Check for msg/CNNData message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cnn_msgs
bool
cnn_msgs__msg__CNNData__are_equal(const cnn_msgs__msg__CNNData * lhs, const cnn_msgs__msg__CNNData * rhs);

/// Copy a msg/CNNData message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_cnn_msgs
bool
cnn_msgs__msg__CNNData__copy(
  const cnn_msgs__msg__CNNData * input,
  cnn_msgs__msg__CNNData * output);

/// Initialize array of msg/CNNData messages.
/**
 * It allocates the memory for the number of elements and calls
 * cnn_msgs__msg__CNNData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cnn_msgs
bool
cnn_msgs__msg__CNNData__Sequence__init(cnn_msgs__msg__CNNData__Sequence * array, size_t size);

/// Finalize array of msg/CNNData messages.
/**
 * It calls
 * cnn_msgs__msg__CNNData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cnn_msgs
void
cnn_msgs__msg__CNNData__Sequence__fini(cnn_msgs__msg__CNNData__Sequence * array);

/// Create array of msg/CNNData messages.
/**
 * It allocates the memory for the array and calls
 * cnn_msgs__msg__CNNData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cnn_msgs
cnn_msgs__msg__CNNData__Sequence *
cnn_msgs__msg__CNNData__Sequence__create(size_t size);

/// Destroy array of msg/CNNData messages.
/**
 * It calls
 * cnn_msgs__msg__CNNData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cnn_msgs
void
cnn_msgs__msg__CNNData__Sequence__destroy(cnn_msgs__msg__CNNData__Sequence * array);

/// Check for msg/CNNData message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cnn_msgs
bool
cnn_msgs__msg__CNNData__Sequence__are_equal(const cnn_msgs__msg__CNNData__Sequence * lhs, const cnn_msgs__msg__CNNData__Sequence * rhs);

/// Copy an array of msg/CNNData messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_cnn_msgs
bool
cnn_msgs__msg__CNNData__Sequence__copy(
  const cnn_msgs__msg__CNNData__Sequence * input,
  cnn_msgs__msg__CNNData__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CNN_MSGS__MSG__DETAIL__CNN_DATA__FUNCTIONS_H_

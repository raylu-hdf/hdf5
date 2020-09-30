/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * Copyright by the Board of Trustees of the University of Illinois.         *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the COPYING file, which can be found at the root of the source code       *
 * distribution tree, or in https://support.hdfgroup.org/ftp/HDF5/releases.  *
 * If you do not have access to either file, you may request a copy from     *
 * help@hdfgroup.org.                                                        *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 * This file contains function prototypes for each exported function in the
 * H5P module.
 */
#ifndef _H5Ppublic_H
#define _H5Ppublic_H

/* System headers needed by this file */

/* Public headers needed by this file */
#include "H5public.h"
#include "H5ACpublic.h"
#include "H5Dpublic.h"
#include "H5Fpublic.h"
#include "H5FDpublic.h"
#include "H5Ipublic.h"
#include "H5Lpublic.h"
#include "H5Opublic.h"
#include "H5MMpublic.h"
#include "H5Tpublic.h"
#include "H5Zpublic.h"


/*****************/
/* Public Macros */
/*****************/

/* When this header is included from a private HDF5 header, don't make calls to H5open() */
#undef H5OPEN
#ifndef _H5private_H
#define H5OPEN        H5open(),
#else   /* _H5private_H */
#define H5OPEN
#endif  /* _H5private_H */

/*
 * The library's property list classes
 */

#define H5P_ROOT                (H5OPEN H5P_CLS_ROOT_ID_g)
#define H5P_OBJECT_CREATE       (H5OPEN H5P_CLS_OBJECT_CREATE_ID_g)
#define H5P_FILE_CREATE         (H5OPEN H5P_CLS_FILE_CREATE_ID_g)
#define H5P_FILE_ACCESS         (H5OPEN H5P_CLS_FILE_ACCESS_ID_g)
#define H5P_DATASET_CREATE      (H5OPEN H5P_CLS_DATASET_CREATE_ID_g)
#define H5P_DATASET_ACCESS      (H5OPEN H5P_CLS_DATASET_ACCESS_ID_g)
#define H5P_DATASET_XFER        (H5OPEN H5P_CLS_DATASET_XFER_ID_g)
#define H5P_FILE_MOUNT          (H5OPEN H5P_CLS_FILE_MOUNT_ID_g)
#define H5P_GROUP_CREATE        (H5OPEN H5P_CLS_GROUP_CREATE_ID_g)
#define H5P_GROUP_ACCESS        (H5OPEN H5P_CLS_GROUP_ACCESS_ID_g)
#define H5P_DATATYPE_CREATE     (H5OPEN H5P_CLS_DATATYPE_CREATE_ID_g)
#define H5P_DATATYPE_ACCESS     (H5OPEN H5P_CLS_DATATYPE_ACCESS_ID_g)
#define H5P_MAP_CREATE          (H5OPEN H5P_CLS_MAP_CREATE_ID_g)
#define H5P_MAP_ACCESS          (H5OPEN H5P_CLS_MAP_ACCESS_ID_g)
#define H5P_STRING_CREATE       (H5OPEN H5P_CLS_STRING_CREATE_ID_g)
#define H5P_ATTRIBUTE_CREATE    (H5OPEN H5P_CLS_ATTRIBUTE_CREATE_ID_g)
#define H5P_ATTRIBUTE_ACCESS    (H5OPEN H5P_CLS_ATTRIBUTE_ACCESS_ID_g)
#define H5P_OBJECT_COPY         (H5OPEN H5P_CLS_OBJECT_COPY_ID_g)
#define H5P_LINK_CREATE         (H5OPEN H5P_CLS_LINK_CREATE_ID_g)
#define H5P_LINK_ACCESS         (H5OPEN H5P_CLS_LINK_ACCESS_ID_g)
#define H5P_VOL_INITIALIZE      (H5OPEN H5P_CLS_VOL_INITIALIZE_ID_g)
#define H5P_REFERENCE_ACCESS    (H5OPEN H5P_CLS_REFERENCE_ACCESS_ID_g)

/*
 * The library's default property lists
 */
#define H5P_FILE_CREATE_DEFAULT        (H5OPEN H5P_LST_FILE_CREATE_ID_g)
#define H5P_FILE_ACCESS_DEFAULT        (H5OPEN H5P_LST_FILE_ACCESS_ID_g)
#define H5P_DATASET_CREATE_DEFAULT     (H5OPEN H5P_LST_DATASET_CREATE_ID_g)
#define H5P_DATASET_ACCESS_DEFAULT     (H5OPEN H5P_LST_DATASET_ACCESS_ID_g)
#define H5P_DATASET_XFER_DEFAULT       (H5OPEN H5P_LST_DATASET_XFER_ID_g)
#define H5P_FILE_MOUNT_DEFAULT         (H5OPEN H5P_LST_FILE_MOUNT_ID_g)
#define H5P_GROUP_CREATE_DEFAULT       (H5OPEN H5P_LST_GROUP_CREATE_ID_g)
#define H5P_GROUP_ACCESS_DEFAULT       (H5OPEN H5P_LST_GROUP_ACCESS_ID_g)
#define H5P_DATATYPE_CREATE_DEFAULT    (H5OPEN H5P_LST_DATATYPE_CREATE_ID_g)
#define H5P_DATATYPE_ACCESS_DEFAULT    (H5OPEN H5P_LST_DATATYPE_ACCESS_ID_g)
#define H5P_MAP_CREATE_DEFAULT         (H5OPEN H5P_LST_MAP_CREATE_ID_g)
#define H5P_MAP_ACCESS_DEFAULT         (H5OPEN H5P_LST_MAP_ACCESS_ID_g)
#define H5P_ATTRIBUTE_CREATE_DEFAULT   (H5OPEN H5P_LST_ATTRIBUTE_CREATE_ID_g)
#define H5P_ATTRIBUTE_ACCESS_DEFAULT   (H5OPEN H5P_LST_ATTRIBUTE_ACCESS_ID_g)
#define H5P_OBJECT_COPY_DEFAULT        (H5OPEN H5P_LST_OBJECT_COPY_ID_g)
#define H5P_LINK_CREATE_DEFAULT        (H5OPEN H5P_LST_LINK_CREATE_ID_g)
#define H5P_LINK_ACCESS_DEFAULT        (H5OPEN H5P_LST_LINK_ACCESS_ID_g)
#define H5P_VOL_INITIALIZE_DEFAULT     (H5OPEN H5P_LST_VOL_INITIALIZE_ID_g)
#define H5P_REFERENCE_ACCESS_DEFAULT   (H5OPEN H5P_LST_REFERENCE_ACCESS_ID_g)

/* Common creation order flags (for links in groups and attributes on objects) */
#define H5P_CRT_ORDER_TRACKED           0x0001
#define H5P_CRT_ORDER_INDEXED           0x0002

/* Default value for all property list classes */
#define H5P_DEFAULT     (hid_t)0

#ifdef __cplusplus
extern "C" {
#endif

/*******************/
/* Public Typedefs */
/*******************/


/* Define property list class callback function pointer types */
//! [H5P_cls_create_func_t_snip]
typedef herr_t (*H5P_cls_create_func_t)(hid_t prop_id, void *create_data);
//! [H5P_cls_create_func_t_snip]

//! [H5P_cls_copy_func_t_snip]
typedef herr_t (*H5P_cls_copy_func_t)(hid_t new_prop_id, hid_t old_prop_id,
                                      void *copy_data);
//! [H5P_cls_copy_func_t_snip]

//! [H5P_cls_close_func_t_snip]
typedef herr_t (*H5P_cls_close_func_t)(hid_t prop_id, void *close_data);
//! [H5P_cls_close_func_t_snip]

/* Define property list callback function pointer types */
//! [H5P_prp_cb1_t_snip]
typedef herr_t (*H5P_prp_cb1_t)(const char *name, size_t size, void *value);
//! [H5P_prp_cb1_t_snip]

//! [H5P_prp_cb2_t_snip]
typedef herr_t (*H5P_prp_cb2_t)(hid_t prop_id, const char *name, size_t size, void *value);
//! [H5P_prp_cb2_t_snip]

typedef H5P_prp_cb1_t H5P_prp_create_func_t;
typedef H5P_prp_cb2_t H5P_prp_set_func_t;
typedef H5P_prp_cb2_t H5P_prp_get_func_t;
typedef herr_t (*H5P_prp_encode_func_t)(const void *value, void **buf, size_t *size);
typedef herr_t (*H5P_prp_decode_func_t)(const void **buf, void *value);
typedef H5P_prp_cb2_t H5P_prp_delete_func_t;
typedef H5P_prp_cb1_t H5P_prp_copy_func_t;
//! [H5P_prp_compare_func_t_snip]
typedef int (*H5P_prp_compare_func_t)(const void *value1, const void *value2, size_t size);
//! [H5P_prp_compare_func_t_snip]
typedef H5P_prp_cb1_t H5P_prp_close_func_t;

/* Define property list iteration function type */
//! [H5P_iterate_t_snip]
typedef herr_t (*H5P_iterate_t)(hid_t id, const char *name, void *iter_data);
//! [H5P_iterate_t_snip]

/* Actual IO mode property */
typedef enum H5D_mpio_actual_chunk_opt_mode_t {
    /* The default value, H5D_MPIO_NO_CHUNK_OPTIMIZATION, is used for all I/O
     * operations that do not use chunk optimizations, including non-collective
     * I/O and contiguous collective I/O.
     */
    H5D_MPIO_NO_CHUNK_OPTIMIZATION = 0,
    H5D_MPIO_LINK_CHUNK,
    H5D_MPIO_MULTI_CHUNK
}  H5D_mpio_actual_chunk_opt_mode_t;

typedef enum H5D_mpio_actual_io_mode_t {
    /* The following four values are conveniently defined as a bit field so that
     * we can switch from the default to independent or collective and then to
     * mixed without having to check the original value.
     *
     * NO_COLLECTIVE means that either collective I/O wasn't requested or that
     * no I/O took place.
     *
     * CHUNK_INDEPENDENT means that collective I/O was requested, but the
     * chunk optimization scheme chose independent I/O for each chunk.
     */
    H5D_MPIO_NO_COLLECTIVE = 0x0,
    H5D_MPIO_CHUNK_INDEPENDENT = 0x1,
    H5D_MPIO_CHUNK_COLLECTIVE = 0x2,
    H5D_MPIO_CHUNK_MIXED = 0x1 | 0x2,

    /* The contiguous case is separate from the bit field. */
    H5D_MPIO_CONTIGUOUS_COLLECTIVE = 0x4
} H5D_mpio_actual_io_mode_t;

/* Broken collective IO property */
typedef enum H5D_mpio_no_collective_cause_t {
    H5D_MPIO_COLLECTIVE = 0x00,
    H5D_MPIO_SET_INDEPENDENT = 0x01,
    H5D_MPIO_DATATYPE_CONVERSION = 0x02,
    H5D_MPIO_DATA_TRANSFORMS = 0x04,
    H5D_MPIO_MPI_OPT_TYPES_ENV_VAR_DISABLED = 0x08,
    H5D_MPIO_NOT_SIMPLE_OR_SCALAR_DATASPACES = 0x10,
    H5D_MPIO_NOT_CONTIGUOUS_OR_CHUNKED_DATASET = 0x20,
    H5D_MPIO_PARALLEL_FILTERED_WRITES_DISABLED = 0x40,
    H5D_MPIO_ERROR_WHILE_CHECKING_COLLECTIVE_POSSIBLE = 0x80,
    H5D_MPIO_NO_COLLECTIVE_MAX_CAUSE = 0x100
} H5D_mpio_no_collective_cause_t;

/********************/
/* Public Variables */
/********************/

/* Property list class IDs */
/* (Internal to library, do not use!  Use macros above) */
H5_DLLVAR hid_t H5P_CLS_ROOT_ID_g;
H5_DLLVAR hid_t H5P_CLS_OBJECT_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_FILE_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_FILE_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_CLS_DATASET_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_DATASET_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_CLS_DATASET_XFER_ID_g;
H5_DLLVAR hid_t H5P_CLS_FILE_MOUNT_ID_g;
H5_DLLVAR hid_t H5P_CLS_GROUP_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_GROUP_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_CLS_DATATYPE_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_DATATYPE_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_CLS_MAP_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_MAP_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_CLS_STRING_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_ATTRIBUTE_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_ATTRIBUTE_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_CLS_OBJECT_COPY_ID_g;
H5_DLLVAR hid_t H5P_CLS_LINK_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_LINK_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_CLS_VOL_INITIALIZE_ID_g;
H5_DLLVAR hid_t H5P_CLS_REFERENCE_ACCESS_ID_g;

/* Default roperty list IDs */
/* (Internal to library, do not use!  Use macros above) */
H5_DLLVAR hid_t H5P_LST_FILE_CREATE_ID_g;
H5_DLLVAR hid_t H5P_LST_FILE_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_LST_DATASET_CREATE_ID_g;
H5_DLLVAR hid_t H5P_LST_DATASET_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_LST_DATASET_XFER_ID_g;
H5_DLLVAR hid_t H5P_LST_FILE_MOUNT_ID_g;
H5_DLLVAR hid_t H5P_LST_GROUP_CREATE_ID_g;
H5_DLLVAR hid_t H5P_LST_GROUP_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_LST_DATATYPE_CREATE_ID_g;
H5_DLLVAR hid_t H5P_LST_DATATYPE_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_LST_MAP_CREATE_ID_g;
H5_DLLVAR hid_t H5P_LST_MAP_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_LST_ATTRIBUTE_CREATE_ID_g;
H5_DLLVAR hid_t H5P_LST_ATTRIBUTE_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_LST_OBJECT_COPY_ID_g;
H5_DLLVAR hid_t H5P_LST_LINK_CREATE_ID_g;
H5_DLLVAR hid_t H5P_LST_LINK_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_LST_VOL_INITIALIZE_ID_g;
H5_DLLVAR hid_t H5P_LST_REFERENCE_ACCESS_ID_g;

/*********************/
/* Public Prototypes */
/*********************/

/* Generic property list routines */
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLO
 *
 * \brief Terminates access to a property list
 *
 * \plist_id
 *
 * \return \herr_t
 *
 * \details H5Pclose() terminates access to a property list. All property
 *          lists should be closed when the application is finished
 *          accessing them. This frees resources used by the property
 *          list.
 *
 * \since 1.0.0
 *
 * -------------------------------------------------------------------------
 */
H5_DLL herr_t H5Pclose(hid_t plist_id);
/**
 *--------------------------------------------------------------------------
 * \ingroup GPLOA
 *
 * \brief Closes an existing property list class
 *
 * \plistcls_id{class}
 *
 * \return \herr_t
 *
 * \details H5Pclose_class() removes a property list class from the library.
 *          Existing property lists of this class will continue to exist,
 *          but new ones are not able to be created.
 *
 * \since 1.4.0
 *
 */
H5_DLL herr_t H5Pclose_class(hid_t class);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLO
 *
 * \brief Copies an existing property list to create a new property list
 *
 * \plist_id
 *
 * \return \hid_t{property list}
 *
 * \details H5Pcopy() copies an existing property list to create a new
 *          property list. The new property list has the same properties
 *          and values as the original property list.
 *
 * \since 1.0.0
 *
 */
H5_DLL hid_t H5Pcopy(hid_t plist_id);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLOA
 *
 * \brief Copies a property from one list or class to another
 *
 * \param[in] dst_id Identifier of the destination property list or class
 * \param[in] src_id Identifier of the source property list or class
 * \param[in] name Name of the property to copy
 *
 * \return \herr_t
 *
 * \details H5Pcopy_prop() copies a property from one property list or
 *          class to another.
 *
 *          If a property is copied from one class to another, all the
 *          property information will be first deleted from the destination
 *          class and then the property information will be copied from the
 *          source class into the destination class.
 *
 *          If a property is copied from one list to another, the property
 *          will be first deleted from the destination list (generating a
 *          call to the close callback for the property, if one exists)
 *          and then the property is copied from the source list to the
 *          destination list (generating a call to the copy callback for
 *          the property, if one exists).
 *
 *          If the property does not exist in the class or list, this
 *          call is equivalent to calling H5Pregister() or H5Pinsert() (for
 *          a class or list, as appropriate) and the create callback will
 *          be called in the case of the property being copied into a list
 *          (if such a callback exists for the property).
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pcopy_prop(hid_t dst_id, hid_t src_id, const
char *name);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLO
 *
 * \brief Creates a new property list as an instance of a property list class
 *
 * \plistcls_id{cls_id}
 *
 * \return \hid_t{property list}
 *
 * \details H5Pcreate() creates a new property list as an instance of
 *          some property list class. The new property list is initialized
 *          with default values for the specified class. The classes are as
 *          follows:
 *
 * <table>
 *   <tr>
 *     <th>Class Identifier</th>
 *     <th>Class Name</th>
 *     <th>Comments</th>
 *   </tr>
 *   <tr>
 *     <td>#H5P_ATTRIBUTE_CREATE</td>
 *     <td>attribute create</td>
 *     <td>Properties for attribute creation</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_DATASET_ACCESS</td>
 *     <td>dataset access</td>
 *     <td>Properties for dataset access</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_DATASET_CREATE</td>
 *     <td>dataset create</td>
 *     <td>Properties for dataset creation</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_DATASET_XFER</td>
 *     <td>data transfer</td>
 *     <td>Properties for raw data transfer</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_DATATYPE_ACCESS</td>
 *     <td>datatype access</td>
 *     <td>Properties for datatype access</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_DATATYPE_CREATE</td>
 *     <td>datatype create</td>
 *     <td>Properties for datatype creation</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_FILE_ACCESS</td>
 *     <td>file access</td>
 *     <td>Properties for file access</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_FILE_CREATE</td>
 *     <td>file create</td>
 *     <td>Properties for file creation</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_FILE_MOUNT</td>
 *     <td>file mount</td>
 *     <td>Properties for file mounting</td>
 *   </tr>
 *   <tr valign="top">
 *     <td>#H5P_GROUP_ACCESS</td>
 *     <td>group access</td>
 *     <td>Properties for group access</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_GROUP_CREATE</td>
 *     <td>group create</td>
 *     <td>Properties for group creation</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_LINK_ACCESS</td>
 *     <td>link access</td>
 *     <td>Properties governing link traversal when accessing objects</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_LINK_CREATE</td>
 *     <td>link create</td>
 *     <td>Properties governing link creation</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_OBJECT_COPY</td>
 *     <td>object copy</td>
 *     <td>Properties governing the object copying process</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_OBJECT_CREATE</td>
 *     <td>object create</td>
 *     <td>Properties for object creation</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_STRING_CREATE</td>
 *     <td>string create</td>
 *     <td>Properties for character encoding when encoding strings or
 *       object names</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_VOL_INITIALIZE</td>
 *     <td>vol initialize</td>
 *     <td>Properties for VOL initialization</td>
 *   </tr>
 * </table>
 *
 * This property list must eventually be closed with H5Pclose();
 * otherwise, errors are likely to occur.
 *
 * \version 1.12.0 The #H5P_VOL_INITIALIZE property list class was added
 * \version 1.8.15 For each class, the class name returned by
 *                 H5Pget_class_name() was added.
 *                 The list of possible Fortran values was updated.
 * \version 1.8.0 The following property list classes were added at this
 *                release: #H5P_DATASET_ACCESS, #H5P_GROUP_CREATE,
 *                #H5P_GROUP_ACCESS, #H5P_DATATYPE_CREATE,
 *                #H5P_DATATYPE_ACCESS, #H5P_ATTRIBUTE_CREATE
 *
 * \since 1.0.0
 *
 * --------------------------------------------------------------------------
 */
H5_DLL hid_t H5Pcreate(hid_t cls_id);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLOA
 *
 * \brief Creates a new property list class
 *
 * \plistcls_id{parent}
 * \param[in] name        Name of property list class to register
 * \param[in] create      Callback routine called when a property list is
 *                        created
 * \param[in] create_data Pointer to user-defined class create data, to be
 *                        passed along to class create callback
 * \param[in] copy        Callback routine called when a property list is
 *                        copied
 * \param[in] copy_data   Pointer to user-defined class copy data, to be
 *                        passed along to class copy callback
 * \param[in] close       Callback routine called when a property list is
 *                        being closed
 * \param[in] close_data  Pointer to user-defined class close data, to be
 *                        passed along to class close callback
 *
 * \return \hid_t{property list class}
 *
 * \details H5Pcreate_class() registers a new property list class with the
 *          library. The new property list class can inherit from an
 *          existing property list class, \p parent, or may be derived
 *          from the default “empty” class, NULL. New classes with
 *          inherited properties from existing classes may not remove
 *          those existing properties, only add or remove their own class
 *          properties. Property list classes defined and supported in the
 *          HDF5 library distribution are listed and briefly described in
 *          H5Pcreate(). The \p create routine is called when a new property
 *          list of this class is being created. The #H5P_cls_create_func_t
 *          callback function is defined as follows:
 *
 *          \todo fix snippets to work, when you click on them.
 *
 *          \snippet this H5P_cls_create_func_t_snip
 *
 *          The parameters to this callback function are defined as follows:
 *          <table>
 *            <tr>
 *              <td>\ref hid_t \c prop_id</td>
 *              <td>IN: The identifier of the property list being created</td>
 *            </tr>
 *            <tr>
 *              <td>\Code{void * create_data}</td>
 *              <td>IN: User pointer to any class creation data required</td>
 *            </tr>
 *          </table>
 *
 *          The \p create routine is called after any registered
 *          \p create function is called for each property value. If the
 *          \p create routine returns a negative value, the new list is not
 *          returned to the user and the property list creation routine returns
 *          an error value.
 *
 *          The \p copy routine is called when an existing property
 *          list of this class is copied. The #H5P_cls_copy_func_t callback
 *          function is defined as follows:
 *          \snippet this H5P_cls_copy_func_t_snip
 *
 *          The parameters to this callback function are defined as follows:
 *          <table>
 *            <tr>
 *              <td>\ref hid_t \c prop_id</td>
 *              <td>IN: The identifier of the property list created by copying</td>
 *            </tr>
 *            <tr>
 *              <td>\Code{void * copy_data}</td>
 *              <td>IN: User pointer to any class copy data required</td>
 *            </tr>
 *          </table>
 *
 *          The \p copy routine is called after any registered \p copy function
 *          is called for each property value. If the \p copy routine returns a
 *          negative value, the new list is not returned to the user and the
 *          property list \p copy routine returns an error value.
 *
 *           The \p close routine is called when a property list of this class
 *           is being closed. The #H5P_cls_close_func_t callback function is
 *           defined as follows:
 *           \snippet this H5P_cls_close_func_t_snip
 *
 *           The parameters to this callback function are defined as follows:
 *           <table>
 *            <tr>
 *              <td>\ref hid_t \c prop_id</td>
 *              <td>IN: The identifier of the property list being closed</td>
 *            </tr>
 *            <tr>
 *              <td>\Code{void * close_data}</td>
 *              <td>IN: User pointer to any class close data required</td>
 *            </tr>
 *          </table>
 *
 *          The \p close routine is called before any registered \p close
 *          function is called for each property value. If the \p close routine
 *          returns a negative value, the property list close routine returns
 *          an error value but the property list is still closed.
 *
 *          H5Pclose_class() can be used to release the property list class
 *          identifier returned by this function so that resources leaks will
 *          not develop.
 *
 * \since 1.4.0
 *
 */
H5_DLL hid_t H5Pcreate_class(hid_t parent, const char *name,
    H5P_cls_create_func_t create, void *create_data,
    H5P_cls_copy_func_t copy, void *copy_data,
    H5P_cls_close_func_t close, void *close_data);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLO
 *
 * \brief Decodes property list received in a binary object buffer and
 *        returns a new property list identifier
 *
 * \param[in] buf Buffer holding the encoded property list
 *
 * \return \hid_tv{object}
 *
 * \details Given a binary property list description in a buffer, H5Pdecode()
 *          reconstructs the HDF5 property list and returns an identifier
 *          for the new property list. The binary description of the property
 *          list is encoded by H5Pencode().
 *
 *          The user is responsible for passing in the correct buffer.
 *
 *          The property list identifier returned by this function should be
 *          released with H5Pclose() when the identifier is no longer needed
 *          so that resource leaks will not develop.
 *
 * \note Some properties cannot be encoded and therefore will not be available
 *       in the decoded property list. These properties are discussed in
 *       H5Pencode().
 *
 * \since 1.10.0
 *
 */
H5_DLL hid_t  H5Pdecode(const void *buf);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLO
 *
 * \brief Encodes the property values in a property list into a binary
 *        buffer
 *
 * \plist_id
 * \param[out] buf    Buffer into which the property list will be encoded.
 *                    If the provided buffer is NULL, the size of the
 *                    buffer required is returned through \p nalloc; the
 *                    function does nothing more.
 * \param[out] nalloc The size of the required buffer
 * \fapl_id
 *
 * \return \herr_t
 *
 * \details H5Pencode2() encodes the property list \p plist_id into the
 *          binary buffer \p buf, according to the file format setting
 *          specified by the file access property list \p fapl_id.
 *
 *          If the required buffer size is unknown, \p buf can be passed
 *          in as NULL and the function will set the required buffer size
 *          in \p nalloc. The buffer can then be created and the property
 *          list encoded with a subsequent H5Pencode2() call.
 *
 *          If the buffer passed in is not big enough to hold the encoded
 *          properties, the H5Pencode2() call can be expected to fail with
 *          a segmentation fault.
 *
 *          The file access property list \p fapl_id is used to
 *          control the encoding via the \a libver_bounds property
 *          (see H5Pset_libver_bounds()). If the \a libver_bounds
 *          property is missing, H5Pencode2() proceeds as if the \a
 *          libver_bounds property were set to (#H5F_LIBVER_EARLIEST,
 *          #H5F_LIBVER_LATEST). (Functionally, H5Pencode1() is identical to
 *          H5Pencode2() with \a libver_bounds set to (#H5F_LIBVER_EARLIEST,
 *          #H5F_LIBVER_LATEST).)
 *          Properties that do not have encode callbacks will be skipped.
 *          There is currently no mechanism to register an encode callback for
 *          a user-defined property, so user-defined properties cannot currently
 *          be encoded.
 *
 *          Some properties cannot be encoded, particularly properties that are
 *          reliant on local context.
 *
 * \note \a Motivation:
 *       This function was introduced in HDF5-1.12 as part of the \a H5Sencode
 *       format change to enable 64-bit selection encodings and a dataspace
 *       selection that is tied to a file.
 *
 * \since 1.12.0
 *
 */
H5_DLL herr_t H5Pencode2(hid_t plist_id, void *buf, size_t *nalloc, hid_t fapl_id);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLOA
 *
 * \brief Compares two property lists or classes for equality
 *
 * \param[in] id1 First property object to be compared
 * \param[in] id2 Second property object to be compared
 *
 * \return \htri_t
 *
 * \details H5Pequal() compares two property lists or classes to determine
 *          whether they are equal to one another.
 *
 *          Either both \p id1 and \p id2 must be property lists or both
 *          must be classes; comparing a list to a class is an error.
 *
 * \since 1.4.0
 *
 */
H5_DLL htri_t H5Pequal(hid_t id1, hid_t id2);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLOA
 *
 * \brief Queries whether a property name exists in a property list or
 *       class
 *
 * \param[in] plist_id   Identifier for the property list or class to query
 * \param[in] name       Name of property to check for
 *
 * \return \htri_t
 *
 * \details  H5Pexist() determines whether a property exists within a
 *           property list or class.
 *
 * \since 1.4.0
 *
 */
H5_DLL htri_t H5Pexist(hid_t plist_id, const char *name);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLOA
 *
 * \brief Queries the value of a property
 *
 * \plist_id
 * \param[in]  name  Name of property to query
 * \param[out] value Pointer to a location to which to copy the value of
 *                   the property
 *
 * \return \herr_t
 *
 * \details H5Pget() retrieves a copy of the value for a property in a
 *          property list. If there is a \p get callback routine registered
 *          for this property, the copy of the value of the property will
 *          first be passed to that routine and any changes to the copy of
 *          the value will be used when returning the property value from
 *          this routine.
 *
 *          This routine may be called for zero-sized properties with the
 *          \p value set to NULL. The \p get routine will be called with
 *          a NULL value if the callback exists.
 *
 *          The property name must exist or this routine will fail.
 *
 *          If the \p get callback routine returns an error, \ value will
 *          not be modified.
 *
 * \since 1.4.0
 *
 */
H5_DLL herr_t H5Pget(hid_t plist_id, const char *name, void * value);
/**
 *-------------------------------------------------------------------------
 *\ingroup GPLO
 *
 * \brief Returns the property list class identifier for a property list
 *
 * \plist_id
 *
 * \return \hid_t{property list class}
 *
 * \details H5Pget_class() returns the property list class identifier for
 *          the property list identified by the \p plist_id parameter.
 *
 *          Note that H5Pget_class() returns a value of #hid_t type, an
 *          internal HDF5 identifier, rather than directly returning a
 *          property list class. That identifier can then be used with
 *          either H5Pequal() or H5Pget_class_name() to determine which
 *          predefined HDF5 property list class H5Pget_class() has returned.
 *
 *          A full list of valid predefined property list classes appears
 *          in the description of H5Pcreate().
 *
 *          Determining the HDF5 property list class name with H5Pequal()
 *          requires a series of H5Pequal() calls in an if-else sequence.
 *          An iterative sequence of H5Pequal() calls can compare the
 *          identifier returned by H5Pget_class() to members of the list of
 *          valid property list class names. A pseudo-code snippet might
 *          read as follows:
 *
 *          \code
 *          plist_class_id = H5Pget_class (dsetA_plist);
 *
 *          if H5Pequal (plist_class_id, H5P_OBJECT_CREATE) = TRUE;
 *              [ H5P_OBJECT_CREATE is the property list class    ]
 *              [ returned by H5Pget_class.                        ]
 *
 *          else if H5Pequal (plist_class_id, H5P_DATASET_CREATE) = TRUE;
 *              [ H5P_DATASET_CREATE is the property list class.  ]
 *
 *          else if H5Pequal (plist_class_id, H5P_DATASET_XFER) = TRUE;
 *              [ H5P_DATASET_XFER is the property list class.    ]
 *
 *          .
 *          .   [ Continuing the iteration until a match is found. ]
 *          .
 *          \endcode
 *
 *          H5Pget_class_name() returns the property list class name directly
 *          as a string:
 *
 *          \code
 *          plist_class_id = H5Pget_class (dsetA_plist);
 *          plist_class_name = H5Pget_class_name (plist_class_id)
 *          \endcode
 *
 *          Note that frequent use of H5Pget_class_name() can become a
 *          performance problem in a high-performance environment. The
 *          H5Pequal() approach is generally much faster.
 *
 * \version 1.6.0 Return type changed in this release.
 * \since 1.0.0
 *
 */
H5_DLL hid_t H5Pget_class(hid_t plist_id);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLOA
 *
 * \brief Retrieves the name of a class
 *
 * \plistcls_id{pclass_id}
 *
 * \return Returns a pointer to an allocated string containing the class
 *         name if successful, and NULL if not successful.
 *
 * \details H5Pget_class_name() retrieves the name of a generic property
 *          list class. The pointer to the name must be freed by the user
 *          with a call to H5free_memory() after each successful call.
 *
 *          <table>
 *           <tr>
 *            <th>Class Name (class identifier) Returned</th>
 *            <th>Property List Class</th>
 *            <th>Expanded Name of the Property List Class</th>
 *            <th>The Class Identifier Used with H5Pcreate</th>
 *            <th>Comments</th>
 *           </tr>
 *           <tr>
 *            <td>attribute create</td>
 *            <td>acpl</td>
 *            <td>Attribute Creation Property List</td>
 *            <td>H5P_ATTRIBUTE_CREATE</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>dataset access</td>
 *            <td>dapl</td>
 *            <td>Dataset Access Property List</td>
 *            <td>H5P_DATASET_ACCESS</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>dataset create</td>
 *            <td>dcpl</td>
 *            <td>Dataset Creation Property List</td>
 *            <td>H5P_DATASET_CREATE</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>data transfer</td>
 *            <td>dxpl</td>
 *            <td>Data Transfer Property List</td>
 *            <td>H5P_DATASET_XFER</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>datatype access</td>
 *            <td> </td>
 *            <td> </td>
 *            <td>H5P_DATATYPE_ACCESS</td>
 *            <td>This class can be created, but there are no properties
 *                in the class currently.
 *            </td>
 *           </tr>
 *           <tr>
 *            <td>datatype create</td>
 *            <td> </td>
 *            <td> </td>
 *            <td>H5P_DATATYPE_CREATE</td>
 *            <td>This class can be created, but there
 *                are no properties in the class currently.</td>
 *           </tr>
 *           <tr>
 *            <td>file access</td>
 *            <td>fapl</td>
 *            <td>File Access Property List</td>
 *            <td>H5P_FILE_ACCESS</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>file create</td>
 *            <td>fcpl</td>
 *            <td>File Creation Property List</td>
 *            <td>H5P_FILE_CREATE</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>file mount</td>
 *            <td>fmpl</td>
 *            <td>File Mount Property List</td>
 *            <td>H5P_FILE_MOUNT</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>group access</td>
 *            <td> </td>
 *            <td> </td>
 *            <td>H5P_GROUP_ACCESS</td>
 *            <td>This class can be created, but there
 *                are no properties in the class currently.</td>
 *           </tr>
 *           <tr>
 *            <td>group create</td>
 *            <td>gcpl</td>
 *            <td>Group Creation Property List</td>
 *            <td>H5P_GROUP_CREATE</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *             <td>link access</td>
 *             <td>lapl</td>
 *             <td>Link Access Property List</td>
 *             <td>H5P_LINK_ACCESS</td>
 *             <td> </td>
 *           </tr>
 *           <tr>
 *            <td>link create</td>
 *            <td>lcpl</td>
 *            <td>Link Creation Property List</td>
 *            <td>H5P_LINK_CREATE</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>object copy</td>
 *            <td>ocpypl</td>
 *            <td>Object Copy Property List</td>
 *            <td>H5P_OBJECT_COPY</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>object create</td>
 *            <td>ocpl</td>
 *            <td>Object Creation Property List</td>
 *            <td>H5P_OBJECT_CREATE</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>string create</td>
 *            <td>strcpl</td>
 *            <td>String Creation Property List</td>
 *            <td>H5P_STRING_CREATE</td>
 *            <td> </td>
 *           </tr>
 *          </table>
 *
 * \since 1.4.0
 *
 */
H5_DLL char *H5Pget_class_name(hid_t pclass_id);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLOA
 *
 * \brief Retrieves the parent class of a property class
 *
 * \plistcls_id{pclass_id}
 *
 * \return \hid_t{parent class object}
 *
 * \details H5Pget_class_parent() retrieves an identifier for the parent
 *          class of a property class.
 *
 * \since 1.4.0
 *
 */
H5_DLL hid_t H5Pget_class_parent(hid_t pclass_id);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLOA
 *
 * \brief  Queries the number of properties in a property list or class
 *
 * \param[in]  id     Identifier for property object to query
 * \param[out] nprops Number of properties in object
 *
 * \return \herr_t
 *
 * \details H5Pget_nprops() retrieves the number of properties in a
 *          property list or property list class.
 *
 *          If \p id is a property list identifier, the current number of
 *          properties in the list is returned in \p nprops.
 *
 *          If \p id is a property list class identifier, the number of
 *          registered properties in the class is returned in \p nprops.
 *
 * \since 1.4.0
 *
 */
H5_DLL herr_t H5Pget_nprops(hid_t id, size_t *nprops);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLOA
 *
 * \brief Queries the size of a property value in bytes
 *
 * \param[in]  id   Identifier of property object to query
 * \param[in]  name Name of property to query
 * \param[out] size Size of property in bytes
 *
 * \return  \herr_t
 *
 * \details H5Pget_size() retrieves the size of a property's value in
 *          bytes. This function operates on both property lists and
 *          property classes.
 *
 *          Zero-sized properties are allowed and return 0.
 *
 * \since 1.4.0
 *
 */
H5_DLL herr_t H5Pget_size(hid_t id, const char *name, size_t *size);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLOA
 *
 * \brief Registers a temporary property with a property list
 *
 * \plist_id
 * \param[in] name    Name of property to create
 * \param[in] size    Size of property in bytes
 * \param[in] value   Initial value for the property
 * \param[in] set     Callback routine called before a new value is copied
 *                    into the property's value
 * \param[in] get     Callback routine called when a property value is
 *                    retrieved from the property
 * \param[in] delete  Callback routine called when a property is deleted
 *                    from a property list
 * \param[in] copy    Callback routine called when a property is copied
 *                    from an existing property list
 * \param[in] compare Callback routine called when a property is compared
 *                    with another property list
 * \param[in] close   Callback routine called when a property list is
 *                    being closed and the property value will be disposed
 *                    of
 *
 * \return \herr_t
 *
 * \details H5Pinsert2() creates a new property in a property
 *          list. The property will exist only in this property list and
 *          copies made from it.
 *
 *          The initial property value must be provided in \p value and
 *          the property value will be set accordingly.
 *
 *          The name of the property must not already exist in this list,
 *          or this routine will fail.
 *
 *          The \p set and \p get callback routines may be set to NULL
 *          if they are not needed.
 *
 *          Zero-sized properties are allowed and do not store any data
 *          in the property list. The default value of a zero-size
 *          property may be set to NULL. They may be used to indicate the
 *          presence or absence of a particular piece of information.
 *
 *          The \p set routine is called before a new value is copied
 *          into the property. The #H5P_prp_set_func_t callback function
 *          is defined as follows:
 *          \snippet this H5P_prp_cb2_t_snip
 *
 *          The parameters to the callback function are defined as follows:
 *          <table>
 *           <tr>
 *            <td>\ref hid_t \c prop_id</td>
 *            <td>IN: The identifier of the property list being
 *                modified</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property being modified</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *             <td>\Code{void * value}</td>
 *             <td>IN: Pointer to new value pointer for the property
 *                 being modified</td>
 *           </tr>
 *          </table>
 *
 *          The \p set routine may modify the value pointer to be set and
 *          those changes will be used when setting the property's value.
 *          If the \p set routine returns a negative value, the new property
 *          value is not copied into the property and the \p  set routine
 *          returns an error value. The \p set routine will be called for
 *          the initial value.
 *
 *          \b Note: The \p set callback function may be useful to range
 *          check the value being set for the property or may perform some
 *          transformation or translation of the value set. The \p get
 *          callback would then reverse the transformation or translation.
 *          A single \p get or \p set callback could handle multiple
 *          properties by performing different actions based on the
 *          property name or other properties in the property list.
 *
 *          The \p get routine is called when a value is retrieved from
 *          a property value. The #H5P_prp_get_func_t callback function
 *          is defined as follows:
 *
 *          \snippet this H5P_prp_cb2_t_snip
 *
 *          The parameters to the above callback function are:
 *
 *          <table>
 *           <tr>
 *            <td>\ref hid_t \c prop_id</td>
 *            <td>IN: The identifier of the property list being queried</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property being queried</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t  size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void *  value}</td>
 *            <td>IN: The value of the property being returned</td>
 *           </tr>
 *          </table>
 *
 *          The \p get routine may modify the value to be returned from
 *          the query and those changes will be preserved. If the \p get
 *          routine returns a negative value, the query routine returns
 *          an error value.
 *
 *          The \p delete routine is called when a property is being
 *          deleted from a property list. The #H5P_prp_delete_func_t
 *          callback function is defined as follows:
 *
 *          \snippet this H5P_prp_cb2_t_snip
 *
 *          The parameters to the above callback function are:
 *
 *          <table>
 *           <tr>
 *            <td>\ref hid_t \c prop_id</td>
 *            <td>IN: The identifier of the property list the property is
 *                being deleted from</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property in the list</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void * value}</td>
 *            <td>IN: The value for the property being deleted</td>
 *           </tr>
 *          </table>
 *
 *          The \p delete routine may modify the value passed in, but the
 *          value is not used by the library when the \p delete routine
 *          returns. If the \p delete routine returns a negative value,
 *          the property list \p delete routine returns an error value but
 *          the property is still deleted.
 *
 *          The \p copy routine is called when a new property list with
 *          this property is being created through a \p copy operation.
 *
 *          The #H5P_prp_copy_func_t callback function is defined as follows:
 *
 *          \snippet this H5P_prp_cb1_t_snip
 *
 *          The parameters to the above callback function are:
 *          <table>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property being copied</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void * value}</td>
 *            <td>IN/OUT: The value for the property being copied</td>
 *           </tr>
 *          </table>
 *
 *          The \p copy routine may modify the value to be set and those
 *          changes will be stored as the new value of the property. If the
 *          \p copy routine returns a negative value, the new property value
 *          is not copied into the property and the copy routine returns an
 *          error value.
 *
 *          The \p compare routine is called when a property list with this
 *          property is compared to another property list with the same
 *          property.
 *
 *          The #H5P_prp_compare_func_t callback function is defined as
 *          follows:
 *
 *          \snippet this H5P_prp_compare_func_t_snip
 *
 *          The parameters to the callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\Code{const void * value1}</td>
 *            <td>IN: The value of the first property to compare</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{const void * value2}</td>
 *            <td>IN: The value of the second property to compare</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *          </table>
 *
 *          The \p compare routine may not modify the values. The \p compare
 *          routine should return a positive value if \p value1 is greater
 *          than \p value2, a negative value if \p value2 is greater than
 *          \p value1 and zero if \p value1 and \p value2 are equal.
 *
 *          The \p close routine is called when a property list with this
 *          property is being closed.
 *
 *          The #H5P_prp_close_func_t callback function is defined as follows:
 *          \snippet this H5P_prp_cb1_t_snip
 *
 *          The parameters to the callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property in the list</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void * value}</td>
 *            <td>IN: The value for the property being closed</td>
 *           </tr>
 *          </table>
 *
 *          The \p close routine may modify the value passed in, the
 *          value is not used by the library when the close routine
 *          returns. If the \p close routine returns a negative value,
 *          the property list \p close routine returns an error value
 *          but the property list is still closed.
 *
 *          \b Note: There is no \p create callback routine for temporary
 *          property list objects; the initial value is assumed to
 *          have any necessary setup already performed on it.
 *
 * \todo "cpp_note" goes here
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pinsert2(hid_t plist_id, const char *name, size_t size,
    void *value, H5P_prp_set_func_t set, H5P_prp_get_func_t get,
    H5P_prp_delete_func_t delete, H5P_prp_copy_func_t copy,
    H5P_prp_compare_func_t compare, H5P_prp_close_func_t close);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLOA
 *
 * \brief Determines whether a property list is a member of a class
 *
 * \plist_id
 * \plistcls_id{pclass_id}
 *
 * \return \htri_t
 *
 * \details H5Pisa_class() checks to determine whether the property list
 *          \p plist_id is a member of the property list class
 *          \p pclass_id.
 *
 * \see H5Pcreate()
 *
 * \since  1.6.0
 *
 */
H5_DLL htri_t H5Pisa_class(hid_t plist_id, hid_t pclass_id);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLOA
 *
 * \brief Iterates over properties in a property class or list
 *
 * \param[in]     id  Identifier of property object to iterate over
 * \param[in,out] idx Index of the property to begin with
 * \param[in]     iter_func  Function pointer to function to be called
 *                           with each property iterated over
 * \param[in,out] iter_data  Pointer to iteration data from user
 *
 * \return On success: the return value of the last call to \p iter_func if
 *         it was non-zero; zero if all properties have been processed.
 *         On Failure, a negative value
 *
 * \details H5Piterate() iterates over the properties in the property
 *          object specified in \p id, which may be either a property
 *          list or a property class, performing a specified operation
 *          on each property in turn.
 *
 *          For each property in the object, \p iter_func and the
 *          additional information specified below are passed to the
 *          #H5P_iterate_t operator function.
 *
 *          The iteration begins with the \p idx-th property in the
 *          object; the next element to be processed by the operator
 *          is returned in \p idx. If \p idx is NULL, the iterator
 *          starts at the first property; since no stopping point is
 *          returned in this case, the iterator cannot be restarted if
 *          one of the calls to its operator returns non-zero.
 *
 *          The prototype for the #H5P_iterate_t operator is as follows:
 *          \snippet this H5P_iterate_t_snip
 *
 *          The operation receives the property list or class
 *          identifier for the object being iterated over, \p id, the
 *          name of the current property within the object, \p name,
 *          and the pointer to the operator data passed in to H5Piterate(),
 *          \p iter_data. The valid return values from an operator are
 *          as follows:
 *
 *          <table>
 *           <tr>
 *            <td>Zero</td>
 *            <td>Causes the iterator to continue, returning zero when all
 *                properties have been processed</td>
 *           </tr>
 *           <tr>
 *            <td>Positive</td>
 *            <td>Causes the iterator to immediately return that positive
 *                value, indicating short-circuit success. The iterator
 *                can be restarted at the index of the next property</td>
 *           </tr>
 *           <tr>
 *            <td>Negative</td>
 *            <td>Causes the iterator to immediately return that value,
 *                indicating failure. The iterator can be restarted at the
 *                index of the next property</td>
 *           </tr>
 *          </table>
 *          H5Piterate() assumes that the properties in the object
 *          identified by \p id remain unchanged through the iteration.
 *          If the membership changes during the iteration, the function's
 *          behavior is undefined.
 *
 *
 * \todo "cpp_note" goes here
 *
 * \since 1.4.0
 *
 */
H5_DLL int H5Piterate(hid_t id, int *idx, H5P_iterate_t iter_func,
            void *iter_data);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLOA
 *
 * \brief Registers a permanent property with a property list class
 *
 * \plistcls_id{cls_id}
 * \param[in] name       Name of property to register
 * \param[in] size       Size of property in bytes
 * \param[in] def_value  Default value for property in newly created
 *                       property lists
 * \param[in] create     Callback routine called when a property list is
 *                       being created and the property value will be
 *                       initialized
 * \param[in] set        Callback routine called before a new value is
 *                       copied into the property's value
 * \param[in] get        Callback routine called when a property value is
 *                       retrieved from the property
 * \param[in] delete     Callback routine called when a property is deleted
 *                       from a property list
 * \param[in] copy       Callback routine called when a property is copied
 *                       from a property list
 * \param[in] compare    Callback routine called when a property is compared
 *                       with another property list
 * \param[in] close      Callback routine called when a property list is
 *                       being closed and the property value will be
 *                       disposed of
 *
 * \return  \herr_t
 *
 * \details H5Pregister2() registers a new property with a property list
 *          class. The \p cls_id identifier can be obtained by calling
 *          H5Pcreate_class(). The property will exist in all property
 *          list objects of \p cl_id created after this routine finishes. The
 *          name of the property must not already exist, or this routine
 *          will fail. The default property value must be provided and all
 *          new property lists created with this property will have the
 *          property value set to the default value. Any of the callback
 *          routines may be set to NULL if they are not needed.
 *
 *          Zero-sized properties are allowed and do not store any data in
 *          the property list. These may be used as flags to indicate the
 *          presence or absence of a particular piece of information. The
 *          default pointer for a zero-sized property may be set to NULL.
 *          The property \p create and \p close callbacks are called for
 *          zero-sized properties, but the \p set and \p get callbacks are
 *          never called.
 *
 *          The \p create routine is called when a new property list with
 *          this property is being created. The #H5P_prp_create_func_t
 *          callback function is defined as follows:
 *
 *          \snippet this H5P_prp_cb1_t_snip
 *
 *          The parameters to this callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property being modified</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void * value}</td>
 *            <td>IN/OUT: The default value for the property being created,
 *                which will be passed to H5Pregister2()</td>
 *           </tr>
 *          </table>
 *
 *          The \p create routine may modify the value to be set and those
 *          changes will be stored as the initial value of the property.
 *          If the \p create routine returns a negative value, the new
 *          property value is not copied into the property and the
 *          \p create routine returns an error value.
 *
 *          The \p set routine is called before a new value is copied into
 *          the property. The #H5P_prp_set_func_t callback function is defined
 *          as follows:
 *
 *          \snippet this H5P_prp_cb2_t_snip
 *
 *          The parameters to this callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\ref hid_t \c prop_id</td>
 *            <td>IN: The identifier of the property list being modified</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property being modified</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void *value}</td>
 *            <td>IN/OUT: Pointer to new value pointer for the property
 *                being modified</td>
 *           </tr>
 *          </table>
 *
 *          The \p set routine may modify the value pointer to be set and
 *          those changes will be used when setting the property's value.
 *          If the \p set routine returns a negative value, the new property
 *          value is not copied into the property and the \p set routine
 *          returns an error value. The \p set routine will not be called
 *          for the initial value; only the \p create routine will be called.
 *
 *          \b Note: The \p set callback function may be useful to range
 *          check the value being set for the property or may perform some
 *          transformation or translation of the value set. The \p get
 *          callback would then reverse the transformation or translation.
 *          A single \p get or \p set callback could handle multiple
 *          properties by performing different actions based on the property
 *          name or other properties in the property list.
 *
 *          The \p get routine is called when a value is retrieved from a
 *          property value. The #H5P_prp_get_func_t callback function is
 *          defined as follows:
 *
 *          \snippet this H5P_prp_cb2_t_snip
 *
 *          The parameters to the callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\ref hid_t \c prop_id</td>
 *            <td>IN: The identifier of the property list being
 *                queried</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property being queried</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void * value}</td>
 *            <td>IN/OUT: The value of the property being returned</td>
 *           </tr>
 *          </table>
 *
 *          The \p get routine may modify the value to be returned from the
 *          query and those changes will be returned to the calling routine.
 *          If the \p set routine returns a negative value, the query
 *          routine returns an error value.
 *
 *          The \p delete routine is called when a property is being
 *          deleted from a property list. The #H5P_prp_delete_func_t
 *          callback function is defined as follows:
 *
 *          \snippet this H5P_prp_cb2_t_snip
 *
 *          The parameters to the callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\ref hid_t \c prop_id</td>
 *            <td>IN: The identifier of the property list the property is
 *                being deleted from</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property in the list</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void * value}</td>
 *            <td>IN: The value for the property being deleted</td>
 *           </tr>
 *          </table>
 *
 *          The \p delete routine may modify the value passed in, but the
 *          value is not used by the library when the \p delete routine
 *          returns. If the \p delete routine returns a negative value,
 *          the property list  delete routine returns an error value but
 *          the property is still deleted.
 *
 *          The \p copy routine is called when a new property list with
 *          this property is being created through a \p copy operation.
 *          The #H5P_prp_copy_func_t callback function is defined as follows:
 *
 *          \snippet this H5P_prp_cb1_t_snip
 *
 *          The parameters to the callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property being copied</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void * value}</td>
 *            <td>IN/OUT: The value for the property being copied</td>
 *           </tr>
 *          </table>
 *
 *          The \p copy routine may modify the value to be set and those
 *          changes will be stored as the new value of the property. If
 *          the \p copy routine returns a negative value, the new
 *          property value is not copied into the property and the \p copy
 *          routine returns an error value.
 *
 *          The \p compare routine is called when a property list with this
 *          property is compared to another property list with the same
 *          property. The #H5P_prp_compare_func_t callback function is
 *          defined as follows:
 *
 *          \snippet this H5P_prp_compare_func_t_snip
 *
 *          The parameters to the callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\Code{const void * value1}</td>
 *            <td>IN: The value of the first property to compare</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{const void * value2}</td>
 *            <td>IN: The value of the second property to compare</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *          </table>
 *
 *          The \p compare routine may not modify the values. The \p compare
 *          routine should return a positive value if \p value1 is greater
 *          than \p value2, a negative value if \p value2 is greater than
 *          \p value1 and zero if \p value1 and \p value2 are equal.
 *
 *          The \p close routine is called when a property list with this
 *          property is being closed. The #H5P_prp_close_func_t callback
 *          function is defined as follows:
 *
 *          \snippet this H5P_prp_cb2_t_snip
 *
 *          The parameters to the callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\ref hid_t \c prop_id</td>
 *            <td>IN: The identifier of the property list being closed</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property in the list</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void * value}</td>
 *            <td>IN: The value for the property being closed</td>
 *           </tr>
 *          </table>
 *
 *          The \p close routine may modify the value passed in, but the
 *          value is not used by the library when the \p close routine returns.
 *          If the \p close routine returns a negative value, the property
 *          list close routine returns an error value but the property list is
 *          still closed.
 *
 * \todo "cpp_note" goes here
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pregister2(hid_t cls_id, const char *name, size_t size,
    void *def_value, H5P_prp_create_func_t create,
    H5P_prp_set_func_t set, H5P_prp_get_func_t get,
    H5P_prp_delete_func_t delete, H5P_prp_copy_func_t copy,
    H5P_prp_compare_func_t compare, H5P_prp_close_func_t close);
/**
 *-------------------------------------------------------------------------
 * \ingroup GPLOA
 *
 * \brief Removes a property from a property list
 *
 * \plist_id
 * \param[in] name Name of property to remove
 *
 * \return \herr_t
 *
 * \details H5Premove() removes a property from a property list. Both
 *          properties which were in existence when the property list was
 *          created (i.e. properties registered with H5Pregister()) and
 *          properties added to the list after it was created (i.e. added
 *          with H5Pinsert1() may be removed from a property list.
 *          Properties do not need to be removed from a property list
 *          before the list itself is closed; they will be released
 *          automatically when H5Pclose() is called.
 *
 *          If a \p close callback exists for the removed property, it
 *          will be called before the property is released.
 *
 * \since 1.4.0
 *
 */
H5_DLL herr_t H5Premove(hid_t plist_id, const char *name);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup GPLOA
 *
 * \brief Sets a property list value
 *
 * \plist_id
 * \param[in] name  Name of property to modify
 * \param[in] value Pointer to value to set the property to
 *
 * \return \herr_t
 *
 * \details H5Pset() sets a new value for a property in a property list.
 *          If there is a \p set callback routine registered for this
 *          property, the \p value will be passed to that routine and any
 *          changes to the \p value will be used when setting the property
 *          value. The information pointed to by the \p value pointer
 *          (possibly modified by the \p set callback) is copied into the
 *          property list value and may be changed by the application
 *          making the H5Pset() call without affecting the property value.
 *
 *          The property name must exist or this routine will fail.
 *
 *          If the \p set callback routine returns an error, the property
 *          value will not be modified.
 *
 *          This routine may not be called for zero-sized properties and
 *          will return an error in that case.
 *
 * \since 1.4.0
 *
 */
H5_DLL herr_t H5Pset(hid_t plist_id, const char *name, const void *value);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup GPLOA
 *
 * \brief Removes a property from a property list class
 *
 * \plistcls_id{pclass_id}
 * \param[in] name Name of property to remove
 *
 * \return \herr_t
 *
 * \details H5Punregister() removes a property from a property list class.
 *          Future property lists created of that class will not contain
 *          this property; existing property lists containing this property
 *          are not affected.
 *
 * \since 1.4.0
 *
 */
H5_DLL herr_t H5Punregister(hid_t pclass_id, const char *name);

/* Object creation property list (OCPL) routines */
/**
 *--------------------------------------------------------------------------
 *
 * \ingroup OCPL
 *
 * \brief Verifies that all required filters are available
 *
 * \plist_id
 *
 * \return \htri_t
 *
 * \details H5Pall_filters_avail() verifies that all of the filters set in
 *         the dataset or group creation property list \p plist_id are
 *         currently available.
 *
 * \version 1.8.5 Function extended to work with group creation property
 *                lists.
 * \since 1.6.0
 *
 */
H5_DLL htri_t H5Pall_filters_avail(hid_t plist_id);
/**
 *--------------------------------------------------------------------------
 *
 * \ingroup OCPL
 *
 * \brief Retrieves tracking and indexing settings for attribute creation
 *        order
 *
 * \plist_id
 * \param[out] crt_order_flags Flags specifying whether to track and
 *             index attribute creation order
 *
 * \return \herr_t
 *
 * \details H5Pget_attr_creation_order() retrieves the settings for
 *          tracking and indexing attribute creation order on an object.
 *
 *          \p plist_id is an object creation property list (\p ocpl),
 *          as it can be a dataset or group creation property list
 *          identifier. The term \p ocpl is used when different types
 *          of objects may be involved.
 *
 *          \p crt_order_flags returns flags with the following meanings:
 *
 *          <table>
 *           <tr>
 *            <td>#H5P_CRT_ORDER_TRACKED</td>
 *            <td>Attribute creation order is tracked but not necessarily
 *                indexed.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5P_CRT_ORDER_INDEXED </td>
 *            <td>Attribute creation order is indexed (requires
 *                #H5P_CRT_ORDER_TRACKED).</td>
 *           </tr>
 *          </table>
 *
 *          If \p crt_order_flags is returned with a value of 0 (zero),
 *          attribute creation order is neither tracked nor indexed.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_attr_creation_order(hid_t plist_id, unsigned *crt_order_flags);
/**
 *--------------------------------------------------------------------------
 *
 * \ingroup OCPL
 *
 * \brief Retrieves attribute storage phase change thresholds
 *
 * \plist_id
 * \param[out] max_compact Maximum number of attributes to be stored in
 *                         compact storage (Default: 8)
 * \param[out] min_dense   Minimum number of attributes to be stored in
 *                         dense storage (Default: 6)
 *
 * \return \herr_t
 *
 * \details H5Pget_attr_phase_change() retrieves threshold values for
 *          attribute storage on an object. These thresholds determine the
 *          point at which attribute storage changes from compact storage
 *          (i.e., storage in the object header) to dense storage (i.e.,
 *          storage in a heap and indexed with a B-tree).
 *
 *          In the general case, attributes are initially kept in compact
 *          storage. When the number of attributes exceeds \p max_compact,
 *          attribute storage switches to dense storage. If the number of
 *          attributes subsequently falls below \p min_dense, the
 *          attributes are returned to compact storage.
 *
 *          If \p max_compact is set to 0 (zero), dense storage always used.
 *
 *          \p plist_id is an object creation property list (\p ocpl), as it
 *          can be a dataset or group creation property list identifier.
 *          The term \p ocpl is used when different types of objects may be
 *          involved.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_attr_phase_change(hid_t plist_id, unsigned *max_compact, unsigned *min_dense);
/**
 *--------------------------------------------------------------------------
 *
 * \ingroup OCPL
 *
 * \brief Returns information about a filter in a pipeline
 *
 * \todo Signature for H5Pget_filter2 is different in H5Pocpl.c than in
 *       H5Ppublic.h
 *
 * \plist_id{plist_id}
 * \param[in] idx    Sequence number within the filter pipeline of the filter
 *                   for which information is sought
 * \param[out] flags Bit vector specifying certain general properties of the
 *                   filter
 * \param[in,out] cd_nelmts Number of elements in \p cd_values
 * \param[out]    cd_values Auxiliary data for the filter
 * \param[in]     namelen   Anticipated number of characters in \p name
 * \param[out]    name      Name of the filter
 * \param[out] filter_config Bit field, as described in H5Zget_filter_info()
 *
 * \return #H5Z_filter_t
 *         - #H5Z_FILTER_DEFLATE     Data compression filter,
 *                                    employing the gzip algorithm
 *         - #H5Z_FILTER_SHUFFLE     Data shuffling filter
 *         - #H5Z_FILTER_FLETCHER32  Error detection filter, employing the
 *                                     Fletcher32 checksum algorithm
 *         - #H5Z_FILTER_SZIP        Data compression filter, employing the
 *                                     SZIP algorithm
 *         - #H5Z_FILTER_NBIT        Data compression filter, employing the
 *                                     N-bit algorithm
 *         - #H5Z_FILTER_SCALEOFFSET Data compression filter, employing the
 *                                     scale-offset algorithm
 *
 * \details H5Pget_filter2() returns information about a filter specified by
 *          its filter number, in a filter pipeline specified by the property
 *          list with which it is associated.
 *
 *          \p plist_id must be a dataset or group creation property list.
 *
 *          \p idx is a value between zero and N-1, as described in
 *          H5Pget_nfilters(). The function will return a negative value if
 *          the filter number is out of range.
 *
 *          The structure of the \p flags argument is discussed in
 *          H5Pset_filter().
 *
 *          On input, \p cd_nelmts indicates the number of entries in the
 *          \p cd_values array, as allocated by the caller; on return,
 *          \p cd_nelmts contains the number of values defined by the filter.
 *
 *          If \p name is a pointer to an array of at least \p namelen bytes,
 *          the filter name will be copied into that array. The name will be
 *          null terminated if \p namelen is large enough. The filter name
 *          returned will be the name appearing in the file, the name
 *          registered for the filter, or an empty string.
 *
 *          \p filter_config is the bit field described in
 *          H5Zget_filter_info().
 *
 * \version 1.8.5 Function extended to work with group creation property
 *                lists.
 * \since 1.8.0
 *
 *--------------------------------------------------------------------------
 */
H5_DLL H5Z_filter_t H5Pget_filter2(hid_t plist_id, unsigned idx,
       unsigned int *flags/*out*/,
       size_t *cd_nelmts/*out*/,
       unsigned cd_values[]/*out*/,
       size_t namelen, char name[],
       unsigned *filter_config /*out*/);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup OCPL
 *
 * \brief Returns information about the specified filter
 *
 * \plist_id
 * \param[in]     filter_id     Filter identifier
 * \param[out]    flags         Bit vector specifying certain general
 *                              properties of the filter
 * \param[in,out] cd_nelmts     Number of elements in \p cd_values
 * \param[out]    cd_values[]   Auxiliary data for the filter
 * \param[in]     namelen       Length of filter name and number of
 *                              elements in \p name
 * \param[out]    name[]        Name of filter
 * \param[out]    filter_config Bit field, as described in
 *                              H5Zget_filter_info()
 *
 * \return \herr_t
 *
 * \details H5Pget_filter_by_id2() returns information about the filter
 *          specified in \p filter_id, a filter identifier.
 *
 *          \p plist_id must be a dataset or group creation property list
 *          and \p filter_id must be in the associated filter pipeline.
 *
 *          The \p filter_id and \p flags parameters are used in the same
 *          manner as described in the discussion of H5Pset_filter().
 *
 *          Aside from the fact that they are used for output, the
 *          parameters \p cd_nelmts and \p cd_values[] are used in the same
 *          manner as described in the discussion of H5Pset_filter(). On
 *          input, the \p cd_nelmts parameter indicates the number of
 *          entries in the \p cd_values[] array allocated by the calling
 *          program; on exit it contains the number of values defined by
 *          the filter.
 *
 *          On input, the \p namelen parameter indicates the number of
 *          characters allocated for the filter name by the calling program
 *          in the array \p name[]. On exit \p name[] contains the name of the
 *          filter with one character of the name in each element of the
 *          array.
 *
 *          \p filter_config is the bit field described in
 *          H5Zget_filter_info().
 *
 *          If the filter specified in \p filter_id is not set for the
 *          property list, an error will be returned and
 *          H5Pget_filter_by_id2() will fail.
 *
 * \version 1.8.5 Function extended to work with group creation property
 *                lists.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_filter_by_id2(hid_t plist_id, H5Z_filter_t filter_id,
       unsigned int *flags/*out*/, size_t *cd_nelmts/*out*/,
       unsigned cd_values[]/*out*/, size_t namelen, char name[]/*out*/,
       unsigned *filter_config/*out*/);
/**
 *-------------------------------------------------------------------------
 * \ingroup OCPL
 *
 * \brief Returns the number of filters in the pipeline
 *
 * \todo Signature for H5Pget_nfilters() is different in H5Pocpl.c than in
 *       H5Ppublic.h.
 *
 * \plist_id
 *
 * \return  Returns the number of filters in the pipeline if successful;
 *          otherwise returns a negative value.
 *
 * \details H5Pget_nfilters() returns the number of filters defined in the
 *          filter pipeline associated with the property list \p plist_id.
 *
 *          In each pipeline, the filters are numbered from 0 through N-1,
 *          where N is the value returned by this function. During output to
 *          the file, the filters are applied in increasing order; during
 *          input from the file, they are applied in decreasing order.
 *
 *          H5Pget_nfilters() returns the number of filters in the pipeline,
 *          including zero (0) if there are none.
 *
 * \since 1.0.0
 *
 *--------------------------------------------------------------------------
 */
H5_DLL int H5Pget_nfilters(hid_t plist_id);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup OCPL
 *
 * \brief Determines whether times associated with an object
 *       are being recorded
 *
 * \plist_id
 * \param[out] track_times Boolean value, 1 (TRUE) or 0 (FALSE),
 *             specifying whether object times are being recorded
 *
 * \return \herr_t
 *
 * \details H5Pget_obj_track_times() queries the object creation property
 *          list, \p plist_id, to determine whether object times are being
 *          recorded.
 *
 *          If \p track_times is returned as 1, times are being recorded;
 *          if \p track_times is returned as 0, times are not being
 *          recorded.
 *
 *          Time data can be retrieved with H5Oget_info(), which will return
 *          it in the #H5O_info_t struct.
 *
 *          If times are not tracked, they will be reported as follows
 *          when queried: 12:00 AM UDT, Jan. 1, 1970
 *
 *          See H5Pset_obj_track_times() for further discussion.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_obj_track_times(hid_t plist_id, hbool_t *track_times);

H5_DLL herr_t H5Pmodify_filter(hid_t plist_id, H5Z_filter_t filter,
        unsigned int flags, size_t cd_nelmts,
        const unsigned int cd_values[/*cd_nelmts*/]);
H5_DLL herr_t H5Premove_filter(hid_t plist_id, H5Z_filter_t filter);
H5_DLL herr_t H5Pset_attr_creation_order(hid_t plist_id, unsigned crt_order_flags);
H5_DLL herr_t H5Pset_attr_phase_change(hid_t plist_id, unsigned max_compact, unsigned min_dense);
/**
 *-------------------------------------------------------------------------
 * \ingroup OCPL
 *
 * \brief Sets deflate (GNU gzip) compression method and compression level
 *
 * \todo H5Pset_deflate prototype does not match source code
 * \plist_id
 * \param[in] level Compression level
 *
 * \return \herr_t
 *
 * \details H5Pset_deflate() sets the deflate compression method and the
 *          compression level, \p level, for a dataset or group creation
 *          property list, \p plist_id.
 *
 *          The filter identifier set in the property list is
 *          #H5Z_FILTER_DEFLATE.
 *
 *          The compression level, \p level, is a value from zero to nine,
 *          inclusive. A compression level of 0 (zero) indicates no
 *          compression; compression improves but speed slows progressively
 *          from levels 1 through 9:
 *
 *          <table>
 *            <tr>
 *              <th>Compression Level</th>
 *              <th>Gzip Action</th>
 *            </tr>
 *            <tr>
 *              <td>0</td>
 *              <td>No compression</td>
 *            </tr>
 *            <tr>
 *              <td>1</td>
 *              <td>Best compression speed; least compression</td>
 *            </tr>
 *           <tr>
 *             <td>2 through 8</td>
 *             <td>Compression improves; speed degrades</td>
 *           </tr>
 *           <tr>
 *             <td>9</td>
 *             <td>Best compression ratio; slowest speed</td>
 *           </tr>
 *          </table>
 *
 *          Note that setting the compression level to 0 (zero) does not turn
 *          off use of the gzip filter; it simply sets the filter to perform
 *          no compression as it processes the data.
 *
 *          HDF5 relies on GNU gzip for this compression.
 *
 * \version 1.8.5 Function extended to work with group creation property lists.
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_deflate(hid_t plist_id, unsigned level);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup OCPL
 *
 * \brief Adds a filter to the filter pipeline
 *
 * \param[in] plist_id  Dataset or group creation property list identifier
 * \param[in] filter    Filter identifier for the filter to be added to the
 *                      pipeline
 * \param[in] flags     Bit vector specifying certain general properties of
 *                      the filter
 * \param[in] cd_nelmts Number of elements in \p c_values
 * \param[in] c_values  Auxiliary data for the filter
 *
 * \return \herr_t
 *
 * \details H5Pset_filter() adds the specified \p filter identifier and
 *          corresponding properties to the end of an output filter
 *          pipeline.
 *
 *          \p plist_id must be either a dataset creation property list or
 *          group creation property list identifier. If \p plist_id is a
 *          dataset creation property list identifier, the filter is added
 *          to the raw data filter pipeline.
 *
 *          If \p plist_id is a group creation property list identifier,
 *          the filter is added to the link filter pipeline, which filters
 *          the fractal heap used to store most of the link metadata in
 *          certain types of groups. The only predefined filters that can
 *          be set in a group creation property list are the gzip filter
 *          (#H5Z_FILTER_DEFLATE) and the Fletcher32 error detection filter
 *          (#H5Z_FILTER_FLETCHER32).
 *
 *          The array \p c_values contains \p cd_nelmts integers which are
 *          auxiliary data for the filter. The integer values will be
 *          stored in the dataset object header as part of the filter
 *          information.
 *
 *          The \p flags argument is a bit vector with the following
 *          fields specifying certain general properties of the filter:
 *
 *          <table>
 *           <tr>
 *            <td>#H5Z_FLAG_OPTIONAL</td>
 *            <td>If this bit is set then the filter is optional. If the
 *                filter fails (see below) during an H5Dwrite() operation
 *                then the filter is just excluded from the pipeline for
 *                the chunk for which it failed; the filter will not
 *                participate in the pipeline during an H5Dread() of the
 *                chunk. This is commonly used for compression filters:
 *                if the filter result would be larger than the input,
 *                then the compression filter returns failure and the
 *                uncompressed data is stored in the file.<br /><br />
 *                This flag should not be set for the Fletcher32 checksum
 *                filter as it will bypass the checksum filter without
 *                reporting checksum errors to an application.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FLAG_MANDATORY</td>
 *            <td>If the filter is required, that is, set to mandatory,
 *                and the filter fails, the library’s behavior depends
 *                on whether the chunk cache is in use:
 *                \li If the chunk cache is enabled, data chunks will
 *                    be flushed to the file during H5Dclose() and the
 *                    library will return the failure in H5Dclose().
 *                \li When the chunk cache is disabled or not big enough,
 *                    or the chunk is being evicted from the cache, the
 *                    failure will happen during H5Dwrite().
 *
 *                In each case, the library will still write to the file
 *                all data chunks that were processed by the filter
 *                before the failure occurred.<br /><br />
 *                For example, assume that an application creates a
 *                dataset of four chunks, the chunk cache is enabled and
 *                is big enough to hold all four chunks, and the filter
 *                fails when it tries to write the fourth chunk. The
 *                actual flush of the chunks will happen during
 *                H5Dclose(), not H5Dwrite(). By the time H5Dclose()
 *                fails, the first three chunks will have been written
 *                to the file. Even though H5Dclose() fails, all the
 *                resources will be released and the file can be closed
 *                properly. <br /><br />
 *                If, however, the filter fails on the second chunk, only
 *                the first chunk will be written to the file as nothing
 *                further can be written once the filter fails.</td>
 *           </tr>
 *          </table>
 *          The \p filter parameter specifies the filter to be set. Valid
 *          pre-defined filter identifiers are as follows:
 *
 *          <table>
 *           <tr>
 *            <td>#H5Z_FILTER_DEFLATE</td>
 *            <td>Data compression filter, employing the gzip
 *                algorithm</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FILTER_SHUFFLE</td>
 *            <td>Data shuffling filter</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FILTER_FLETCHER32</td>
 *            <td>Error detection filter, employing the Fletcher32
 *                checksum algorithm</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FILTER_SZIP</td>
 *            <td>Data compression filter, employing the SZIP
 *                algorithm</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FILTER_NBIT</td>
 *            <td>Data compression filter, employing the N-Bit
 *                algorithm</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FILTER_SCALEOFFSET</td>
 *            <td>Data compression filter, employing the scale-offset
 *                algorithm</td>
 *           </tr>
 *          </table>
 *          Also see H5Pset_edc_check() and H5Pset_filter_callback().
 *
 * \note When a non-empty filter pipeline is used with a group creation
 *       property list, the group will be created with the new group file
 *       format. The filters will come into play only when dense storage
 *       is used (see H5Pset_link_phase_change()) and will be applied to
 *       the group’s fractal heap. The fractal heap will contain most of
 *       the the group’s link metadata, including link names.
 *
 * \note When working with group creation property lists, if you are
 *       adding a filter that is not in HDF5’s set of predefined filters,
 *       i.e., a user-defined or third-party filter, you must first
 *       determine that the filter will work for a group. See the
 *       discussion of the set local and can apply callback functions
 *       in H5Zregister().
 *
 * \note If multiple filters are set for a property list, they will be
 *       applied to each chunk of raw data for datasets or each block
 *       of the fractal heap for groups in the order in which they were
 *       set.
 *
 * \note Filters can be applied only to chunked datasets; they cannot be
 *       used with other dataset storage methods, such as contiguous,
 *       compact, or external datasets.
 *
 * \note Dataset elements of variable-length and dataset region
 *       reference datatypes are stored in separate structures in the
 *       file called heaps. Filters cannot currently be applied to
 *       these heaps.
 *
 * \note <b>Filter Behavior in HDF5:</b><br />
 *       Filters can be inserted into the HDF5 pipeline to perform
 *       functions such as compression and conversion. As such, they are
 *       a very flexible aspect of HDF5; for example, a user-defined
 *       filter could provide encryption for an HDF5 dataset.
 *
 * \note A filter can be declared as either required or optional.
 *       Required is the default status; optional status must be
 *       explicitly declared.
 *
 * \note A required filter that fails or is not defined causes an
 *       entire output operation to fail; if it was applied when the
 *       data was written, such a filter will cause an input operation
 *       to fail.
 *
 * \note The following table summarizes required filter behavior.
 *          <table>
 *           <tr>
 *            <th></th>
 *            <th>Required FILTER_X not available</th>
 *            <th>FILTER_X available</th>
 *           </tr>
 *           <tr>
 *            <td>H5Pset_<FILTER_X></td>
 *            <td>Will fail.</td>
 *            <td>Will succeed.</td>
 *           </tr>
 *           <tr>
 *            <td>H5Dwrite with FILTER_X set</td>
 *            <td>Will fail.</td>
 *            <td>Will succeed; FILTER_X will be applied to
 *                the data.</td>
 *           </tr>
 *           <tr>
 *            <td>H5Dread with FILTER_X set</td>
 *            <td>Will fail.</td>
 *            <td>Will succeed.</td>
 *           </tr>
 *          </table>
 * \note An optional filter can be set for an HDF5 dataset even when
 *       the filter is not available. Such a filter can then be
 *       applied to the dataset when it becomes available on the
 *       original system or when the file containing the dataset is
 *       processed on a system on which it is available.
 *
 * \note A filter can be declared as optional through the use of the
 *       #H5Z_FLAG_OPTIONAL flag with H5Pset_filter().
 *
 * \note Consider a situation where one is creating files that will
 *       normally be used only on systems where the optional (and
 *       fictional) filter FILTER_Z is routinely available. One can
 *       create those files on system A, which lacks FILTER_Z, create
 *       chunked datasets in the files with FILTER_Z defined in the
 *       dataset creation property list, and even write data to those
 *       datasets. The dataset object header will indicate that FILTER_Z
 *       has been associated with this dataset. But since system A does
 *       not have FILTER_Z, dataset chunks will be written without it
 *       being applied.
 *
 * \note HDF5 has a mechanism for determining whether chunks are
 *       actually written with the filters specified in the object
 *       header, so while the filter remains unavailable, system A will
 *       be able to read the data. Once the file is moved to system B,
 *       where FILTER_Z is available, HDF5 will apply FILTER_Z to any
 *       data rewritten or new data written in these datasets. Dataset
 *       chunks that have been written on system B will then be
 *       unreadable on system A; chunks that have not been re-written
 *       since being written on system A will remain readable on system
 *       A. All chunks will be readable on system B.
 *
 * \note The following table summarizes optional filter behavior.
 *          <table>
 *           <tr>
 *            <th></th>
 *            <th>FILTER_Z not available</th>
 *            <th>FILTER_Z available<br /> with encode and decode</th>
 *            <th>FILTER_Z available decode only</th>
 *           </tr>
 *           <tr>
 *            <td>H5Pset_<FILTER_Z></td>
 *            <td>Will succeed.</td>
 *            <td>Will succeed.</td>
 *            <td>Will succeed.</td>
 *           </tr>
 *           <tr>
 *            <td>H5Dread with FILTER_Z set</td>
 *            <td>Will succeed if FILTER_Z has not actually<br />
 *                been applied to data.</td>
 *            <td>Will succeed.</td>
 *            <td>Will succeed.</td>
 *           </tr>
 *           <tr>
 *            <td>H5Dwrite with FILTER_Z set</td>
 *            <td>Will succeed;<br />
 *                FILTER_Z will not be applied to the data.</td>
 *            <td>Will succeed;<br />
 *            FILTER_Z will be applied to the data.</td>
 *            <td>Will succeed;<br />
 *            FILTER_Z will not be applied to the data.</td>
 *           </tr>
 *          </table>
 * \note The above principles apply generally in the use of HDF5
 *       optional filters insofar as HDF5 does as much as possible to
 *       complete an operation when an optional filter is unavailable.
 *       (The SZIP filter is an exception to this rule; see H5Pset_szip()
 *       for details.)
 *
 * \todo Removed several references to links to documentation
 *
 * \version 1.8.5 Function applied to group creation property lists.
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pset_filter(hid_t plist_id, H5Z_filter_t filter,
        unsigned int flags, size_t cd_nelmts,
        const unsigned int c_values[]);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup OCPL
 *
 * \brief Sets up use of the Fletcher32 checksum filter
 *
 * \param[in] plist_id Dataset or group creation property list identifier
 *
 * \return \herr_t
 *
 * \details H5Pset_fletcher32() sets the Fletcher32 checksum filter in the
 *          dataset or group creation property list \p plist_id.
 *
 * \attention The Fletcher32 EDC checksum filter was added in HDF5 Release
 *            1.6.0. In the original implementation, however, the checksum
 *            value was calculated incorrectly on little-endian systems.
 *            The error was fixed in HDF5 Release 1.6.3.
 *
 * \attention As a result of this fix, an HDF5 library of Release 1.6.0
 *            through Release 1.6.2 cannot read a dataset created or written
 *            with Release 1.6.3 or later if the dataset was created with
 *            the checksum filter and the filter is enabled in the reading
 *            library. (Libraries of Release 1.6.3 and later understand the
 *            earlier error and compensate appropriately.)
 *
 * \attention \b Work-around: An HDF5 library of Release 1.6.2 or earlier
 *            will be able to read a dataset created or written with the
 *            checksum filter by an HDF5 library of Release 1.6.3 or later
 *            if the checksum filter is disabled for the read operation.
 *            This can be accomplished via a call to H5Pset_edc_check()
 *            with the value #H5Z_DISABLE_EDC in the second parameter.
 *            This has the obvious drawback that the application will be
 *            unable to verify the checksum, but the data does remain
 *            accessible.
 *
 * \version 1.8.5 Function extended to work with group creation property
 *                lists.
 * \version 1.6.3 Error in checksum calculation on little-endian systems
 *                corrected in this release.
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pset_fletcher32(hid_t plist_id);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup OCPL
 *
 * \brief Sets the recording of times associated with an object
 *
 * \param[in] plist_id    Object creation property list identifier
 * \param[in] track_times Boolean value, 1 or 0, specifying whether object
 *                        times are to be tracked
 *
 * \return \herr_t
 *
 * \details H5Pset_obj_track_times() sets a property in the object creation
 *          property list, \p plist_id, that governs the recording of times
 *          associated with an object.
 *
 *          If \p track_times is set to 1, time data will be recorded. If
 *          \p track_times is set to 0, time data will not be recorded.
 *
 *          Time data can be retrieved with H5Oget_info(), which will
 *          return it in the #H5O_info_t struct.
 *
 *          If times are not tracked, they will be reported as follows when queried:
 *            \Code{ 12:00 AM UDT, Jan. 1, 1970}
 *
 *          That date and time are commonly used to represent the beginning of the UNIX epoch.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_obj_track_times(hid_t plist_id, hbool_t track_times);

/* File creation property list (FCPL) routines */
H5_DLL herr_t H5Pget_file_space_page_size(hid_t plist_id, hsize_t *fsp_size);
H5_DLL herr_t H5Pget_file_space_strategy(hid_t plist_id, H5F_fspace_strategy_t *strategy, hbool_t *persist, hsize_t *threshold);
H5_DLL herr_t H5Pget_istore_k(hid_t plist_id, unsigned *ik/*out*/);
H5_DLL herr_t H5Pget_shared_mesg_index(hid_t plist_id, unsigned index_num, unsigned *mesg_type_flags, unsigned *min_mesg_size);
H5_DLL herr_t H5Pget_shared_mesg_nindexes(hid_t plist_id, unsigned *nindexes);
H5_DLL herr_t H5Pget_shared_mesg_phase_change(hid_t plist_id, unsigned *max_list, unsigned *min_btree);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FCPL
 *
 * \brief Retrieves the size of the offsets and lengths used in an HDF5
 *        file
 *
 * \fcpl_id{plist_id}
 * \param[out] sizeof_addr Pointer to location to return offset size in
 *             bytes
 * \param[out] sizeof_size Pointer to location to return length size in
 *             bytes
 *
 * \return \herr_t
 *
 * \details H5Pget_sizes() retrieves the size of the offsets and lengths
 *          used in an HDF5 file. This function is only valid for file
 *          creation property lists.
 *
 * \since  1.0.0
 *
 */
H5_DLL herr_t H5Pget_sizes(hid_t plist_id, size_t *sizeof_addr/*out*/,
       size_t *sizeof_size/*out*/);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FCPL
 *
 * \brief Retrieves the size of a user block
 *
 * \fcpl_id{plist_id}
 * \param[out] size  Pointer to location to return user-block size
 *
 * \return \herr_t
 *
 * \details H5Pget_userblock() retrieves the size of a user block in a
 *          file creation property list.
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pget_userblock(hid_t plist_id, hsize_t *size);
H5_DLL herr_t H5Pget_sym_k(hid_t plist_id, unsigned *ik/*out*/, unsigned *lk/*out*/);
H5_DLL herr_t H5Pset_file_space_strategy(hid_t plist_id, H5F_fspace_strategy_t strategy, hbool_t persist, hsize_t threshold);
H5_DLL herr_t H5Pset_file_space_page_size(hid_t plist_id, hsize_t fsp_size);
H5_DLL herr_t H5Pset_istore_k(hid_t plist_id, unsigned ik);
H5_DLL herr_t H5Pset_shared_mesg_index(hid_t plist_id, unsigned index_num, unsigned mesg_type_flags, unsigned min_mesg_size);
H5_DLL herr_t H5Pset_shared_mesg_nindexes(hid_t plist_id, unsigned nindexes);
H5_DLL herr_t H5Pset_shared_mesg_phase_change(hid_t plist_id, unsigned max_list, unsigned min_btree);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FCPL
 *
 * \brief Sets the byte size of the offsets and lengths used to address
 *        objects in an HDF5 file
 *
 * \fcpl_id{plist_id}
 * \param[in] sizeof_addr Size of an object offset in bytes
 * \param[in] sizeof_size Size of an object length in bytes
 *
 * \return \herr_t
 *
 * \details H5Pset_sizes() sets the byte size of the offsets and lengths
 *          used to address objects in an HDF5 file. This function is only
 *          valid for file creation property lists. Passing in a value
 *          of 0 for one of the parameters retains the current value. The
 *          default value for both values is the same as sizeof(hsize_t)
 *          in the library (normally 8 bytes). Valid values currently
 *          are 2, 4, 8 and 16.
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_sizes(hid_t plist_id, size_t sizeof_addr,
       size_t sizeof_size);
H5_DLL herr_t H5Pset_sym_k(hid_t plist_id, unsigned ik, unsigned lk);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FCPL
 *
 * \brief Sets user block size
 *
 * \fcpl_id{plist_id}
 * \param[in] size Size of the user-block in bytes
 *
 * \return  \herr_t
 *
 * \details H5Pset_userblock() sets the user block size of a file creation
 *          property list. The default user block size is 0; it may be set
 *          to any power of 2 equal to 512 or greater (512, 1024, 2048, etc.).
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_userblock(hid_t plist_id, hsize_t size);

/* File access property list (FAPL) routines */
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FAPL
 *
 * \brief Retrieves the current settings for alignment properties from a
 *        file access property list
 *
 * \fapl_id
 * \param[out] threshold Pointer to location of return threshold value
 * \param[out] alignment Pointer to location of return alignment value
 *
 * \return \herr_t
 *
 * \details H5Pget_alignment() retrieves the current settings for
 *          alignment properties from a file access property list. The
 *          \p threshold and/or \p alignment pointers may be null
 *          pointers (NULL).
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pget_alignment(hid_t fapl_id, hsize_t *threshold/*out*/,
    hsize_t *alignment/*out*/);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FAPL
 *
 * \brief Queries the raw data chunk cache parameters
 *
 * \fapl_id{plist_id}
 * \param[in,out] mdc_nelmts  <i>No longer used</i>
 * \param[in,out] rdcc_nslots Number of elements (objects) in the raw data
 *                            chunk cache
 * \param[in,out] rdcc_nbytes Total size of the raw data chunk cache, in
 *                            bytes
 * \param[in,out] rdcc_w0     Preemption policy
 *
 * \return \herr_t
 *
 * \details H5Pget_cache() retrieves the maximum possible number of
 *          elements in the raw data chunk cache, the maximum possible
 *          number of bytes in the raw data chunk cache, and the
 *          preemption policy value.
 *
 *          Any (or all) arguments may be null pointers, in which case
 *          the corresponding datum is not returned.
 *
 *          Note that the \p mdc_nelmts parameter is no longer used.
 *
 * \version 1.8.0 Use of the \p mdc_nelmts parameter discontinued.
 *                Metadata cache configuration is managed with
 *                H5Pset_mdc_config() and H5Pget_mdc_config()
 * \version 1.6.0 The \p rdcc_nbytes and \p rdcc_nslots parameters changed
 *                from type int to size_t.
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pget_cache(hid_t plist_id,
       int *mdc_nelmts, /* out */
       size_t *rdcc_nslots/*out*/,
       size_t *rdcc_nbytes/*out*/, double *rdcc_w0);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FAPL
 *
 * \brief Gets information about the write tracking feature used by
 *        the core VFD
 *
 * \fapl_id
 * \param[out] is_enabled Whether the feature is enabled
 * \param[out] page_size  Size, in bytes, of write aggregation pages
 *
 * \return \herr_t
 *
 * \details H5Pget_core_write_tracking() retrieves information about the
 *          write tracking feature used by the core VFD.
 *
 *          When a file is created or opened for writing using the core
 *          virtual file driver (VFD) with the backing store option turned
 *          on, the VFD can be configured to track changes to the file
 *          and only write out the modified bytes. To avoid a large number
 *          of small writes, the changes can be aggregated into pages of
 *          a user-specified size. The core VFD is also known as the
 *          memory VFD. The driver identifier is #H5FD_CORE.
 *
 * \note This function is only for use with the core VFD and must be used
 *       after the call to H5Pset_fapl_core(). It is an error to use this
 *       function with any other VFD.
 *
 * \note This function only applies to the backing store write operation
 *       which typically occurs when the file is flushed or closed. This
 *       function has no relationship to the increment parameter passed
 *       to H5Pset_fapl_core().
 *
 * \note For optimum performance, the \p page_size parameter should be
 *       a power of two.
 *
 * \since 1.8.13
 *
 */
H5_DLL herr_t H5Pget_core_write_tracking(hid_t fapl_id, hbool_t *is_enabled, size_t *page_size);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FAPL
 *
 * \brief Returns low-lever driver identifier
 *
 * \plist_id
 *
 * \return \hid_t{low level driver}
 *
 * \details H5Pget_driver() returns the identifier of the low-level file
 *          driver associated with the file access property list or
 *          data transfer property list \p plist_id.
 *
 *          Valid driver identifiers distributed with HDF5 are listed and
 *          described in the following table.
 *
 *          <table>
 *           <tr>
 *            <th>Driver Name</th>
 *            <th>Driver Identifier</th>
 *            <th>Description</th>
 *            <th>Related Function</th>
 *           </tr>
 *           <tr>
 *            <td>POSIX</td>
 *            <td>#H5FD_SEC2</td>
 *            <td>This driver uses POSIX file-system functions like read and
 *                write to perform I/O to a single, permanent file on local disk
 *                with no system buffering. This driver is POSIX-compliant and is
 *                the default file driver for all systems.</td>
 *            <td>H5Pset_fapl_sec2()</td>
 *           </tr>
 *           <tr>
 *            <td>Direct</td>
 *            <td>#H5FD_DIRECT</td>
 *            <td>This is the #H5FD_SEC2 driver except data is written to or
 *                read from the file synchronously without being cached by the
 *                system.</td>
 *            <td>H5Pset_fapl_direct()</td>
 *           </tr>
 *           <tr>
 *            <td>Log</td>
 *            <td>#H5FD_LOG</td>
 *            <td>This is the #H5FD_SEC2 driver with logging capabilities.</td>
 *            <td>H5Pset_fapl_log()</td>
 *           </tr>
 *           <tr>
 *            <td>Windows</td>
 *            <td>#H5FD_WINDOWS</td>
 *            <td>This driver was modified in HDF5-1.8.8 to be a wrapper of the
 *                POSIX driver, #H5FD_SEC2. This change should not affect user
 *                applications.</td>
 *            <td>H5Pset_fapl_windows()</td>
 *           </tr>
 *           <tr>
 *            <td>STDIO</td>
 *            <td>#H5FD_STDIO</td>
 *            <td>This driver uses functions from the standard C stdio.h to
 *                perform I/O to a single, permanent file on local disk with
 *                additional system buffering.</td>
 *            <td>H5Pset_fapl_stdio()</td>
 *           </tr>
 *           <tr>
 *            <td>Memory</td>
 *            <td>#H5FD_CORE</td>
 *            <td>With this driver, an application can work with a file in
 *                memory for faster reads and writes. File contents are kept in
 *                memory until the file is closed. At closing, the memory version
 *                of the file can be written back to disk or abandoned.</td>
 *            <td>H5Pset_fapl_core()</td>
 *           </tr>
 *           <tr>
 *            <td>Family</td>
 *            <td>#H5FD_FAMILY</td>
 *            <td>With this driver, the HDF5 file’s address space is partitioned
 *                into pieces and sent to separate storage files using an
 *                underlying driver of the user’s choice. This driver is for
 *                systems that do not support files larger than 2 gigabytes.</td>
 *            <td>H5Pset_fapl_family()</td>
 *           </tr>
 *           <tr>
 *            <td>Multi</td>
 *            <td>#H5FD_MULTI</td>
 *            <td>With this driver, data can be stored in multiple files
 *                according to the type of the data. I/O might work better if
 *                data is stored in separate files based on the type of data.
 *                The Split driver is a special case of this driver.</td>
 *            <td>H5Pset_fapl_multi()</td>
 *           </tr>
 *           <tr>
 *            <td>Parallel</td>
 *            <td>#H5FD_MPIO</td>
 *            <td>This is the standard HDF5 file driver for parallel file
 *                systems. This driver uses the MPI standard for both
 *                communication and file I/O.</td>
 *            <td>H5Pset_fapl_mpio()</td>
 *           </tr>
 *           <tr>
 *            <td>Parallel POSIX</td>
 *            <td>H5FD_MPIPOSIX</td>
 *            <td>This driver is no longer available.</td>
 *            <td></td>
 *           </tr>
 *           <tr>
 *            <td>Stream</td>
 *            <td>H5FD_STREAM</td>
 *            <td>This driver is no longer available.</td>
 *            <td></td>
 *           </tr>
 *          </table>
 *
 *          This list does not include custom drivers that might be
 *          defined and registered by a user.
 *
 *          The returned driver identifier is only valid as long as the
 *          file driver remains registered.
 *
 *
 * \since 1.4.0
 *
 */
H5_DLL hid_t H5Pget_driver(hid_t plist_id);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FAPL
 *
 * \brief Returns a pointer to file driver information
 *
 * \param[in] plist_id File access or data transfer property list
 *                     identifier
 *
 * \return Returns a pointer to a struct containing low-level driver
 *         information. Otherwise returns NULL. NULL is also returned if
 *         no driver-specific properties have been registered. No error
 *         is pushed on the stack in this case.
 *
 * \details H5Pget_driver_info() returns a pointer to file driver-specific
 *          information for the low-level driver associated with the file
 *          access or data transfer property list \p plist_id.
 *
 *          The pointer returned by this function points to an “uncopied”
 *          struct. Driver-specific versions of that struct are defined
 *          for each low-level driver in the relevant source code file
 *          H5FD*.c. For example, the struct used for the MULTI driver is
 *          #H5FD_multi_fapl_t defined in H5FDmulti.c.
 *
 *          If no driver-specific properties have been registered,
 *          H5Pget_driver_info() returns NULL.
 *
 * \note H5Pget_driver_info() and H5Pset_driver() are used only when
 *       creating a virtual file driver (VFD) in the virtual file
 *       layer (VFL).
 *
 * \version 1.10.1 Return value was changed from void * to const void *.
 * \version 1.8.2 Function publicized in this release; previous releases
 *                described this function only in the virtual file driver
 *                documentation.
 *
 */
H5_DLL const void *H5Pget_driver_info(hid_t plist_id);
H5_DLL herr_t H5Pget_elink_file_cache_size(hid_t plist_id, unsigned *efc_size);
H5_DLL herr_t H5Pget_evict_on_close(hid_t fapl_id, hbool_t *evict_on_close);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FAPL
 *
 * \brief Retrieves a data offset from the file access property list
 *
 * \fapl_id
 * \param[out] offset Offset in bytes within the HDF5 file
 *
 * \return \herr_t
 *
 * \details H5Pget_family_offset() retrieves the value of offset from the
 *          file access property list \p fapl_id so that the user
 *          application can retrieve a file handle for low-level access to
 *          a particular member of a family of files. The file handle is
 *          retrieved with a separate call to H5Fget_vfd_handle() (or,
 *          in special circumstances, to H5FDget_vfd_handle()).
 *
 * \todo References the VFL documentation.
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pget_family_offset(hid_t fapl_id, hsize_t *offset);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FAPL
 *
 * \brief Returns the file close degree
 *
 * \fapl_id
 * \param[out] degree Pointer to a location to which to return the file
 *                    close degree property, the value of \p degree
 *
 * \return \herr_t
 *
 * \details H5Pget_fclose_degree() returns the current setting of the file
 *          close degree property \p degree in the file access property
 *          list \p fapl_id. The value of \p degree determines how
 *          aggressively H5Fclose() deals with objects within a file that
 *          remain open when H5Fclose() is called to close that file.
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pget_fclose_degree(hid_t fapl_id, H5F_close_degree_t *degree);
H5_DLL herr_t H5Pget_file_image(hid_t fapl_id, void **buf_ptr_ptr, size_t *buf_len_ptr);
H5_DLL herr_t H5Pget_file_image_callbacks(hid_t fapl_id,
       H5FD_file_image_callbacks_t *callbacks_ptr);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FAPL
 *
 * \brief Returns garbage collecting references setting
 *
 * \fapl_id
 * \param[out] gc_ref Flag returning the state of reference garbage
 *                    collection. A returned value of 1 indicates that
 *                    garbage collection is on while 0 indicates that
 *                    garbage collection is off.
 *
 * \return \herr_t
 *
 * \details H5Pget_gc_references() returns the current setting for the
 *          garbage collection references property from the specified
 *          file access property list. The garbage collection references
 *          property is set by H5Pset_gc_references().
 *
 * \since 1.2.0
 *
 */
H5_DLL herr_t H5Pget_gc_references(hid_t fapl_id, unsigned *gc_ref/*out*/);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FAPL
 *
 * \brief Retrieves library version bounds settings that indirectly control
 *        the format versions used when creating objects
 *
 * \fapl_id{plist_id}
 * \param[out] low  The earliest version of the library that will be used
 *                  for writing objects
 * \param[out] high The latest version of the library that will be used for
 *                  writing objects
 *
 * \return \herr_t
 *
 * \details H5Pget_libver_bounds() retrieves the lower and upper bounds on
 *          the HDF5 library release versions that indirectly determine the
 *          object format versions used when creating objects in the file.
 *
 *          This property is retrieved from the file access property list
 *          specified by the parameter \p fapl_id.
 *
 *          The value returned in the parameters \p low and \p high is one
 *          of the enumerated values in the #H5F_libver_t struct, which is
 *          defined in H5Fpublic.h.
 *
 * \version 1.10.2 Add #H5F_LIBVER_V18 to the enumerated defines in
 *                 #H5F_libver_t
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_libver_bounds(hid_t plist_id, H5F_libver_t *low,
    H5F_libver_t *high);
H5_DLL herr_t H5Pget_mdc_config(hid_t     plist_id,
       H5AC_cache_config_t * config_ptr);    /* out */
H5_DLL herr_t H5Pget_mdc_image_config(hid_t plist_id, H5AC_cache_image_config_t *config_ptr /*out*/);
H5_DLL herr_t H5Pget_mdc_log_options(hid_t plist_id, hbool_t *is_enabled, char *location, size_t *location_size, hbool_t *start_on_access);
H5_DLL herr_t H5Pget_meta_block_size(hid_t fapl_id, hsize_t *size/*out*/);
H5_DLL herr_t H5Pget_metadata_read_attempts(hid_t plist_id, unsigned *attempts);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FAPL
 *
 * \brief Retrieves type of data property for MULTI driver
 *
 * \param[in]  fapl_id File access property list or data transfer property
 *                     list identifier
 * \param[out] type    Type of data
 *
 * \return \herr_t
 *
 * \details H5Pget_multi_type() retrieves the type of data setting from
 *          the file access or data transfer property list \p fapl_id.
 *          This enables a user application to specify the type of data
 *          the application wishes to access so that the application can
 *          retrieve a file handle for low-level access to the particular
 *          member of a set of MULTI files in which that type of data is
 *          stored. The file handle is retrieved with a separate call to
 *          H5Fget_vfd_handle() (or, in special circumstances, to
 *          H5FDget_vfd_handle(); see the Virtual File Layer documentation
 *          for more information.
 *
 *          The type of data returned in \p type will be one of those
 *          listed in the discussion of the \p type parameter in the the
 *          description of the function H5Pset_multi_type().
 *
 *          Use of this function is only appropriate for an HDF5 file
 *          written as a set of files with the MULTI file driver.
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pget_multi_type(hid_t fapl_id, H5FD_mem_t *type);
H5_DLL herr_t H5Pget_object_flush_cb(hid_t plist_id, H5F_flush_cb_t *func, void **udata);
H5_DLL herr_t H5Pget_page_buffer_size(hid_t plist_id, size_t *buf_size, unsigned *min_meta_per, unsigned *min_raw_per);
H5_DLL herr_t H5Pget_sieve_buf_size(hid_t fapl_id, size_t *size/*out*/);
H5_DLL herr_t H5Pget_small_data_block_size(hid_t fapl_id, hsize_t *size/*out*/);
H5_DLL herr_t H5Pget_vol_id(hid_t plist_id, hid_t *vol_id);
H5_DLL herr_t H5Pget_vol_info(hid_t plist_id, void **vol_info);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FAPL
 *
 * \brief Sets alignment properties of a file access property list
 *
 * \fapl_id
 * \param[in] threshold Threshold value. Note that setting the threshold
 *                      value to 0 (zero) has the effect of a special case,
 *                      forcing everything to be aligned
 * \param[in] alignment Alignment value
 *
 * \return \herr_t
 *
 * \details H5Pset_alignment() sets the alignment properties of a
 *          file access property list so that any file object greater
 *          than or equal in size to \p threshold bytes will be aligned
 *          on an address which is a multiple of \p alignment. The
 *          addresses are relative to the end of the user block; the
 *          alignment is calculated by subtracting the user block size
 *          from the absolute file address and then adjusting the address
 *          to be a multiple of \p alignment.
 *
 *          Default values for \p threshold and \p alignment are one,
 *          implying no alignment. Generally the default values will
 *          result in the best performance for single-process access to
 *          the file. For MPI IO and other parallel systems, choose an
 *          alignment which is a multiple of the disk block size.
 *
 *          If the file space handling strategy is set to
 *          #H5F_FSPACE_STRATEGY_PAGE, then the alignment set via this
 *          routine is ignored. The file space handling strategy is set
 *          by H5Pset_file_space_strategy().
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_alignment(hid_t fapl_id, hsize_t threshold,
    hsize_t alignment);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FAPL
 *
 * \brief Sets the raw data chunk cache parameters
 *
 * \fapl_id{plist_id}
 * \param[in] mdc_nelmts No longer used; any value passed is ignored
 * \param[in] rdcc_nslots The number of chunk slots in the raw data chunk
 *                        cache for this dataset. Increasing this value
 *                        reduces the number of cache collisions, but
 *                        slightly increases the memory used. Due to the
 *                        hashing strategy, this value should ideally be a
 *                        prime number. As a rule of thumb, this value
 *                        should be at least 10 times the number of chunks
 *                        that can fit in \p rdcc_nbytes bytes. For
 *                        maximum performance, this value should be set
 *                        approximately 100 times that number of chunks.
 *                        The default value is 521.
 * \param[in] rdcc_nbytes Total size of the raw data chunk cache in bytes.
 *                        The default size is 1 MB per dataset.
 * \param[in] rdcc_w0     The chunk preemption policy for all datasets.
 *                        This must be between 0 and 1 inclusive and
 *                        indicates the weighting according to which chunks
 *                        which have been fully read or written are
 *                        penalized when determining which chunks to flush
 *                        from cache. A value of 0 means fully read or
 *                        written chunks are treated no differently than
 *                        other chunks (the preemption is strictly LRU)
 *                        while a value of 1 means fully read or written
 *                        chunks are always preempted before other chunks.
 *                        If your application only reads or writes data once,
 *                        this can be safely set to 1. Otherwise, this should
 *                        be set lower depending on how often you re-read or
 *                        re-write the same data. The default value is 0.75.
 *                        If the value passed is #H5D_CHUNK_CACHE_W0_DEFAULT,
 *                        then the property will not be set on the dataset
 *                        access property list, and the parameter will come
 *                        from the file access property list.
 *
 * \return \herr_t
 *
 * \details H5Pset_cache() sets the number of elements, the total number of
 *          bytes, and the preemption policy value for all datasets in a file
 *          on the file’s file access property list.
 *
 *          The raw data chunk cache inserts chunks into the cache by first
 *          computing a hash value using the address of a chunk and then by
 *          using that hash value as the chunk’s index into the table of
 *          cached chunks. In other words, the size of this hash table and the
 *          number of possible hash values is determined by the \p rdcc_nslots
 *          parameter. If a different chunk in the cache has the same hash value,
 *          a collision will occur, which will reduce efficiency. If inserting
 *          the chunk into the cache would cause the cache to be too big, then
 *          the cache will be pruned according to the \p rdcc_w0 parameter.
 *
 *          The \p mdc_nelmts parameter is no longer used; any value passed
 *          in that parameter will be ignored.
 *
 * \note \b Motivation: Setting raw data chunk cache parameters
 *       can be done with H5Pset_cache(), H5Pset_chunk_cache(),
 *       or a combination of both. H5Pset_cache() is used to
 *       adjust the chunk cache parameters for all datasets via
 *       a global setting for the file, and H5Pset_chunk_cache()
 *       is used to adjust the chunk cache parameters for
 *       individual datasets. When both are used, parameters
 *       set with H5Pset_chunk_cache() will override any parameters
 *       set with H5Pset_cache().
 *
 * \note Optimum chunk cache parameters may vary widely depending
 *       on different data layout and access patterns. For datasets
 *       with low performance requirements for example, changing
 *       the cache settings can save memory.
 *
 * \note Note: Raw dataset chunk caching is not currently
 *       supported when using the MPI I/O and MPI POSIX file drivers
 *       in read/write mode; see H5Pset_fapl_mpio() and
 *       H5Pset_fapl_mpiposix(), respectively. When using one of these
 *       file drivers, all calls to H5Dread() and H5Dwrite() will access
 *       the disk directly, and H5Pset_cache() will have no effect on
 *       performance.
 *
 * \note Raw dataset chunk caching is supported when these drivers are
 *       used in read-only mode.
 *
 * \todo Check on H5Pset_fapl_mpio() and H5Pset_fapl_mpiposix().
 *
 * \version 1.8.0 The use of the \p mdc_nelmts parameter was discontinued.
 *                Metadata cache configuration is managed with
 *                H5Pset_mdc_config() and H5Pget_mdc_config().
 * \version 1.6.0 The \p rdcc_nbytes and \p rdcc_nelmts parameters
 *                changed from type int to size_t.
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_cache(hid_t plist_id, int mdc_nelmts,
       size_t rdcc_nslots, size_t rdcc_nbytes,
       double rdcc_w0);
H5_DLL herr_t H5Pset_core_write_tracking(hid_t fapl_id, hbool_t is_enabled, size_t page_size);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FAPL
 *
 * \brief Sets a file driver
 *
 * \plist_id
 * \param[in] driver_id   The new driver identifier
 * \param[in] driver_info Optional struct containing driver properties
 *
 * \return \herr_t
 *
 * \details H5Pset_driver() sets the file driver, driver_id, for a file
 *          access or data transfer property list, \p plist_id, and
 *          supplies an optional struct containing the driver-specific
 *          properties, \p driver_info.
 *
 *          The driver properties will be copied into the property list
 *          and the reference count on the driver will be incremented,
 *          allowing the caller to close the driver identifier but still
 *          use the property list.
 *
 * \version 1.8.2 Function publicized in this release; previous releases
 *                described this function only in the virtual file driver
 *                documentation.
 *
 */
H5_DLL herr_t H5Pset_driver(hid_t plist_id, hid_t driver_id,
        const void *driver_info);
H5_DLL herr_t H5Pset_family_offset(hid_t fapl_id, hsize_t offset);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FAPL
 *
 * \brief Sets the file close degree
 *
 * \fapl_id
 * \param[in] degree Pointer to a location containing the file close
 *           degree property, the value of \p degree
 *
 * \return \herr_t
 *
 * \details H5Pset_fclose_degree() sets the file close degree property
 *          \p degree in the file access property list \p fapl_id.
 *
 *          The value of \p degree determines how aggressively
 *          H5Fclose() deals with objects within a file that remain open
 *          when H5Fclose() is called to close that file. \p degree can
 *          have any one of four valid values:
 *
 *          <table>
 *           <tr>
 *            <th>Degree name</th>
 *            <th>H5Fclose behavior with no open object in file</th>
 *            <th>H5Fclose behavior with open object(s) in file</th>
 *           </tr>
 *           <tr>
 *            <td>#H5F_CLOSE_WEAK</td>
 *            <td>Actual file is closed.</td>
 *            <td>Access to file identifier is terminated; actual file
 *                close is delayed until all objects in file are closed
 *            </td>
 *           </tr>
 *           <tr>
 *            <td>#H5F_CLOSE_SEMI</td>
 *            <td>Actual file is closed.</td>
 *            <td>Function returns FAILURE</td>
 *           </tr>
 *           <tr>
 *            <td>#H5F_CLOSE_STRONG</td>
 *            <td>Actual file is closed.</td>
 *            <td>All open objects remaining in the file are closed then
 *                file is closed</td>
 *           </tr>
 *           <tr>
 *            <td>#H5F_CLOSE_DEFAULT</td>
 *            <td>The VFL driver chooses the behavior. Currently, all VFL
 *            drivers set this value to #H5F_CLOSE_WEAK, except for the
 *            MPI-I/O driver, which sets it to #H5F_CLOSE_SEMI.</td>
 *            <td></td>
 *           </tr>
 *
 *          </table>
 * \warning If a file is opened multiple times without being closed, each
 *          open operation must use the same file close degree setting.
 *          For example, if a file is already open with #H5F_CLOSE_WEAK,
 *          an H5Fopen() call with #H5F_CLOSE_STRONG will fail.
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pset_fclose_degree(hid_t fapl_id, H5F_close_degree_t degree);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup FAPL
 *
 * \brief Controls the range of library release versions used when creating
 *        objects in a file
 *
 * \fapl_id{plist_id}
 * \param[in] low  The earliest version of the library that will be used
 *                 for writing objects
 * \param[in] high The latest version of the library that will be used for
 *                 writing objects
 *
 * \return \herr_t
 *
 * \details H5Pset_libver_bounds() controls the range of library release
 *          versions that will be used when creating objects in a file.
 *          The object format versions are determined indirectly from the
 *          library release versions specified in the call.
 *
 *          This property is set in the file access property list
 *          specified by the parameter \p fapl_id.
 *
 *          The parameter \p low sets the earliest possible format
 *          versions that the library will use when creating objects in
 *          the file.  Note that earliest possible is different from
 *          earliest, as some features introduced in library versions
 *          later than 1.0.0 resulted in updates to object formats.
 *          The parameter \p high sets the latest format versions that
 *          the library will be allowed to use when creating objects in
 *          the file.
 *
 *          The parameters \p low and \p high must be one of the
 *          enumerated values in the #H5F_libver_t struct, which is
 *          defined in H5Fpublic.h.
 *
 *          The macro #H5F_LIBVER_LATEST is aliased to the highest
 *          enumerated value in #H5F_libver_t, indicating that this is
 *          currently the latest format available.
 *
 *          The library supports the following five pairs of
 *          (\p low, \p high) combinations as derived from the values
 *          in #H5F_libver_t:
 *
 *          <table>
 *           <tr>
 *            <th>Value of \p low and \p high</th>
 *            <th>Result</th>
 *           </tr>
 *           <tr>
 *            <td>\p low=#H5F_LIBVER_EARLIEST<br />
 *                \p high=#H5F_LIBVER_V18</td>
 *            <td>
 *              \li The library will create objects with the earliest
 *                  possible format versions.
 *              \li The library will allow objects to be created with the
 *                  latest format versions available to library release 1.8.x.
 *              \li API calls that create objects or features that are
 *                  available to versions of the library greater than 1.8.x
 *                  release will fail.
 *             </td>
 *           </tr>
 *           <tr>
 *            <td>\p low=#H5F_LIBVER_EARLIEST<br />
 *                \p high=#H5F_LIBVER_V110</td>
 *            <td>
 *             \li The library will create objects with the earliest possible
 *                 format versions.
 *             \li The library will allow objects to be created with the latest
 *                 format versions available to library release 1.10.x.
 *                 Since 1.10.x is also #H5F_LIBVER_LATEST, there is no upper
 *                 limit on the format versions to use.  For example, if a newer
 *                 format version is required to support a feature e.g. virtual
 *                 dataset, this setting will allow the object to be created.
 *             \li This is the library default setting and provides the greatest
 *                 format compatibility.
 *            </td>
 *           </tr>
 *           <tr>
 *            <td>\p low=#H5F_LIBVER_V18<br />
 *                \p high=#H5F_LIBVER_V18</td>
 *            <td>
 *             \li The library will create objects with the latest format versions
 *                 available to library release 1.8.x.
 *             \li API calls that create objects or features that are available
 *                 to versions of the library greater than 1.8.x release will fail.
 *             \li Earlier versions of the library may not be able to access
 *                 objects created with this setting.</td>
 *           </tr>
 *           <tr>
 *            <td>\p low=#H5F_LIBVER_V18<br />
 *                \p high=#H5F_LIBVER_V110</td>
 *            <td>
 *              \li The library will create objects with the latest format versions
 *                  available to library release 1.8.x.
 *              \li The library will allow objects to be created with the latest
 *                  format versions available to library release 1.10.x.
 *                  Since 1.10.x is also #H5F_LIBVER_LATEST, there is no upper limit
 *                  on the format versions to use.  For example, if a newer format
 *                  version is required to support a feature e.g. virtual dataset,
 *                  this setting will allow the object to be created.
 *              \li Earlier versions of the library may not be able to access
 *                  objects created with this setting.</td>
 *           </tr>
 *           <tr>
 *            <td>\p low=#H5F_LIBVER_V110<br />
 *                \p high=#H5F_LIBVER_V110
 *             </td>
 *             <td>
 *              \li The library will create objects with the latest format versions
 *                  available to library release 1.10.x.
 *              \li The library will allow objects to be created with the latest
 *                  format versions available to library release 1.10.x.
 *                  Since 1.10.x is also #H5F_LIBVER_LATEST, there is no upper limit
 *                  on the format versions to use. For example, if a newer format
 *                  version is required to support a feature e.g. virtual dataset,
 *                  this setting will allow the object to be created.
 *              \li This setting allows users to take advantage of the latest
 *                  features and performance enhancements in the library. However,
 *                  objects written with this setting may be accessible to a smaller
 *                  range of library versions than would be the case if low is set
 *                  to #H5F_LIBVER_EARLIEST.
 *              \li Earlier versions of the library may not be able to access objects created with this setting.
 *            </td>
 *           </tr>
 *          </table>
 *
 * \version 1.10.2 #H5F_LIBVER_V18 added to the enumerated defines in #H5F_libver_t.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_libver_bounds(hid_t plist_id, H5F_libver_t low,
    H5F_libver_t high);
H5_DLL herr_t H5Pset_mdc_config(hid_t    plist_id,
       H5AC_cache_config_t * config_ptr);
H5_DLL herr_t H5Pset_gc_references(hid_t fapl_id, unsigned gc_ref);
H5_DLL herr_t H5Pset_meta_block_size(hid_t fapl_id, hsize_t size);
H5_DLL herr_t H5Pset_sieve_buf_size(hid_t fapl_id, size_t size);
H5_DLL herr_t H5Pset_small_data_block_size(hid_t fapl_id, hsize_t size);
H5_DLL herr_t H5Pset_elink_file_cache_size(hid_t plist_id, unsigned efc_size);
H5_DLL herr_t H5Pset_file_image(hid_t fapl_id, void *buf_ptr, size_t buf_len);
H5_DLL herr_t H5Pset_file_image_callbacks(hid_t fapl_id,
       H5FD_file_image_callbacks_t *callbacks_ptr);
H5_DLL herr_t H5Pset_metadata_read_attempts(hid_t plist_id, unsigned attempts);
H5_DLL herr_t H5Pset_object_flush_cb(hid_t plist_id, H5F_flush_cb_t func, void *udata);
H5_DLL herr_t H5Pset_mdc_log_options(hid_t plist_id, hbool_t is_enabled, const char *location, hbool_t start_on_access);
H5_DLL herr_t H5Pset_evict_on_close(hid_t fapl_id, hbool_t evict_on_close);

#ifdef H5_HAVE_PARALLEL
H5_DLL herr_t H5Pset_all_coll_metadata_ops(hid_t plist_id, hbool_t is_collective);
H5_DLL herr_t H5Pget_all_coll_metadata_ops(hid_t plist_id, hbool_t *is_collective);
H5_DLL herr_t H5Pset_coll_metadata_write(hid_t plist_id, hbool_t is_collective);
H5_DLL herr_t H5Pget_coll_metadata_write(hid_t plist_id, hbool_t *is_collective);
H5_DLL herr_t H5Pget_mpi_params(hid_t fapl_id, MPI_Comm *comm, MPI_Info *info);
H5_DLL herr_t H5Pset_mpi_params(hid_t fapl_id, MPI_Comm comm, MPI_Info info);
#endif /* H5_HAVE_PARALLEL */

H5_DLL herr_t H5Pset_mdc_image_config(hid_t plist_id, H5AC_cache_image_config_t *config_ptr);
H5_DLL herr_t H5Pset_page_buffer_size(hid_t plist_id, size_t buf_size, unsigned min_meta_per, unsigned min_raw_per);
H5_DLL herr_t H5Pset_multi_type(hid_t fapl_id, H5FD_mem_t type);
H5_DLL herr_t H5Pset_vol(hid_t plist_id, hid_t new_vol_id, const void *new_vol_info);

/* Dataset creation property list (DCPL) routines */
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Determines whether fill value is defined
 *
 * \dcpl_id{plist}
 * \param[out] status Status of fill value in property list
 *
 * \return \herr_t
 *
 * \details H5Pfill_value_defined() determines whether a fill value is
 *          defined in the dataset creation property list \p plist. Valid
 *          values returned in status are as follows:
 *
 *          <table>
 *           <tr>
 *            <td>#H5D_FILL_VALUE_UNDEFINED</td>
 *            <td>Fill value is undefined.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_FILL_VALUE_DEFAULT</td>
 *            <td>Fill value is the library default.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_FILL_VALUE_USER_DEFINED</td>
 *            <td>Fill value is defined by the application.</td>
 *           </tr>
 *          </table>
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pfill_value_defined(hid_t plist, H5D_fill_value_t *status);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Retrieves the timing for storage space allocation
 *
 * \dcpl_id{plist_id}
 * \param[out] alloc_time The timing setting for allocating dataset
 *                        storage space
 *
 * \return \herr_t
 *
 * \details H5Pget_alloc_time() retrieves the timing for allocating storage
 *          space for a dataset's raw data. This property is set in the
 *          dataset creation property list \p plist_id. The timing setting
 *          is returned in \p alloc_time as one of the following values:
 *
 *          <table>
 *           <tr>
 *            <td>#H5D_ALLOC_TIME_DEFAULT</td>
 *            <td>Uses the default allocation time, based on the dataset
 *                storage method. <br />See the \p alloc_time description in
 *                H5Pset_alloc_time() for default allocation times for
 *                various storage methods.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_ALLOC_TIME_EARLY</td>
 *            <td>All space is allocated when the dataset is created.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_ALLOC_TIME_INCR</td>
 *            <td>Space is allocated incrementally as data is written
 *                to the dataset.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_ALLOC_TIME_LATE</td>
 *            <td>All space is allocated when data is first written to
 *                the dataset.</td>
 *           </tr>
 *          </table>
 *
 * \note H5Pget_alloc_time() is designed to work in concert with the
 *       dataset fill value and fill value write time properties, set
 *       with the functions H5Pget_fill_value() and H5Pget_fill_time().
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pget_alloc_time(hid_t plist_id, H5D_alloc_time_t
    *alloc_time/*out*/);
/**
 *-------------------------------------------------------------------------
 * \ingroup DCPL
 *
 * \brief Retrieves the size of chunks for the raw data of a chunked
 *        layout dataset
 *
 * \dcpl_id{plist_id}
 * \param[in]  max_ndims Size of the \p dims array
 * \param[out] dim Array to store the chunk dimensions
 *
 * \return Returns chunk dimensionality if successful;
 *         otherwise returns a negative value.
 *
 * \details H5Pget_chunk() retrieves the size of chunks for the raw data
 *          of a chunked layout dataset. This function is only valid for
 *          dataset creation property lists. At most, \p max_ndims elements
 *          of \p dim will be initialized.
 *
 * \since 1.0.0
 *
 */
H5_DLL int H5Pget_chunk(hid_t plist_id, int max_ndims, hsize_t dim[]/*out*/);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Retrieves the edge chunk option setting from a dataset creation
 *        property list
 *
 * \dcpl_id{plist_id}
 * \param[out] opts  Edge chunk option flag. Valid values are described in
 *                   H5Pset_chunk_opts(). The option status can be
 *                   retrieved using the bitwise AND operator ( & ). For
 *                   example, the expression
 *                   (opts&#H5D_CHUNK_DONT_FILTER_PARTIAL_CHUNKS) will
 *                   evaluate to #H5D_CHUNK_DONT_FILTER_PARTIAL_CHUNKS if
 *                   that option has been enabled. Otherwise, it will
 *                   evaluate to 0 (zero).
 *
 * \return \herr_t
 *
 * \details H5Pget_chunk_opts() retrieves the edge chunk option setting
 *          stored in the dataset creation property list \p plist_id.
 *
 * \since 1.10.0
 *
 */
H5_DLL herr_t H5Pget_chunk_opts(hid_t plist_id, unsigned *opts);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Retrieves the setting for whether or not to create minimized
 *        dataset object headers
 *
 * \dcpl_id
 * \param[out] minimize  Flag indicating whether the library will or will
 *                       not create minimized dataset object headers
 *
 * \return \herr_t
 *
 * \details H5Pget_dset_no_attrs_hint() retrieves the
 *          <i>no dataset attributes</i> hint setting for the dataset
 *          creation property list \p dcpl_id. This setting is used to
 *          inform the library to create minimized dataset object headers
 *          when TRUE. The setting value is returned in the boolean pointer
 *          \p minimize.
 *
 * \since 1.10.5
 *
 */
H5_DLL herr_t H5Pget_dset_no_attrs_hint(hid_t dcpl_id, hbool_t *minimize);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Returns information about an external file
 *
 * \dcpl_id{plist_id}
 * \param[in]  idx       External file index
 * \param[in]  name_size Maximum length of \p name array
 * \param[out] name      Name of the external file
 * \param[out] offset    Pointer to a location to return an offset value
 * \param[out] size      Pointer to a location to return the size of the
 *                       external file data
 *
 * \return \herr_t
 *
 * \details H5Pget_external() returns information about an external file.
 *          The external file is specified by its index, \p idx, which
 *          is a number from zero to N-1, where N is the value returned
 *          by H5Pget_external_count(). At most \p name_size characters
 *          are copied into the \p name array. If the external file name
 *          is longer than \p name_size with the null terminator, the
 *          return value is not null terminated (similar to strncpy()).
 *
 *          If \p name_size is zero or \p name is the null pointer, the
 *          external file name is not returned. If \p offset or \p size
 *          are null pointers then the corresponding information is not
 *          returned.
 *
 * \version 1.6.4 \p idx parameter type changed to unsigned.
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pget_external(hid_t plist_id, unsigned idx, size_t name_size,
          char *name/*out*/, off_t *offset/*out*/,
          hsize_t *size/*out*/);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Returns the number of external files for a dataset
 *
 * \dcpl_id{plist_id}
 *
 * \return Returns the number of external files if successful; otherwise
 *         returns a negative value.
 *
 * \details H5Pget_external_count() returns the number of external files
 *          for the specified dataset.
 *
 * \since 1.0.0
 *
 */
H5_DLL int H5Pget_external_count(hid_t plist_id);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Retrieves the time when fill values are written to a dataset
 *
 * \dcpl_id{plist_id}
 * \param[out] fill_time Setting for the timing of writing fill values to
 *                       the dataset
 *
 * \return \herr_t
 *
 * \details H5Pget_fill_time() examines the dataset creation property list
 *          \p plist_id to determine when fill values are to be written to
 *          a dataset. Valid values returned in \p fill_time are as
 *          follows:
 *
 *          <table>
 *           <tr>
 *            <td>#H5D_FILL_TIME_IFSET</td>
 *            <td>Fill values are written to the dataset when storage
 *                space is allocated only if there is a user-defined fill
 *                value, i.e., one set with H5Pset_fill_value(). (Default)
 *             </td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_FILL_TIME_ALLOC</td>
 *            <td>Fill values are written to the dataset when storage
 *                space is allocated.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_FILL_TIME_NEVER</td>
 *            <td>Fill values are never written to the dataset.</td>
 *           </tr>
 *          </table>
 *
 * \note H5Pget_fill_time() is designed to work in coordination with the
 *       dataset fill value and dataset storage allocation time properties,
 *       retrieved with the functions H5Pget_fill_value() and
 *       H5Pget_alloc_time().
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pget_fill_time(hid_t plist_id, H5D_fill_time_t
    *fill_time/*out*/);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Retrieves a dataset fill value
 *
 * \dcpl_id{plist_id}
 * \param[in]  type_id Datatype identifier for the value passed via
 *                     \p value
 * \param[out] value   Pointer to buffer to contain the returned
 *                     fill value
 *
 * \return \herr_t
 *
 * \details H5Pget_fill_value() returns the dataset fill value defined in
 *          the dataset creation property list \p plist_id. The fill value
 *          is returned through the \p value pointer and will be converted
 *          to the datatype specified  by \p type_id. This datatype may
 *          differ from the fill value datatype in the property list, but
 *          the HDF5 library must be able to convert between the two
 *          datatypes.
 *
 *          If the fill value is undefined, i.e., set to NULL in the
 *          property list, H5Pget_fill_value() will return an error.
 *          H5Pfill_value_defined() should be used to check for this
 *          condition before H5Pget_fill_value() is called.
 *
 *          Memory must be allocated by the calling application.
 *
 * \note H5Pget_fill_value() is designed to coordinate with the dataset
 *       storage allocation time and fill value write time properties,
 *       which can be retrieved with the functions H5Pget_alloc_time()
 *       and H5Pget_fill_time(), respectively.
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pget_fill_value(hid_t plist_id, hid_t type_id,
     void *value/*out*/);
/**
 *-------------------------------------------------------------------------
 * \ingroup DCPL
 *
 * \brief Returns the layout of the raw data for a dataset
 *
 * \dcpl_id{plist_id}
 *
 * \return Returns the layout type (a non-negative value) of a dataset
 *         creation property list if successful. Valid return values are:
 *         - #H5D_COMPACT: Raw data is stored in the object header in the
 *                        file.
 *         - #H5D_CONTIGUOUS: Raw data is stored separately from the object
 *                           header in one contiguous chunk in the file.
 *         - #H5D_CHUNKED: Raw data is stored separately from the object
 *                        header in chunks in separate locations in the
 *                        file.
 *         - #H5D_VIRTUAL: Raw data is drawn from multiple datasets in
 *                        different files.
 * \return
 *         Otherwise, returns a negative value indicating failure.
 *
 * \details H5Pget_layout() returns the layout of the raw data for a
 *          dataset. This function is only valid for dataset creation
 *          property lists.
 *
 *          Note that a compact storage layout may affect writing data to
 *          the dataset with parallel applications. See the H5Dwrite()
 *          documentation for details.
 *
 * \version 1.10.0 #H5D_VIRTUAL added in this release.
 *
 * \since 1.0.0
 *
 */
H5_DLL H5D_layout_t H5Pget_layout(hid_t plist_id);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Gets the number of mappings for the virtual dataset
 *
 * \dcpl_id
 * \param[out] count The number of mappings
 *
 * \return \herr_t
 *
 * \details H5Pget_virtual_count() gets the number of mappings for a
 *          virtual dataset that has the creation property list specified
 *          by \p dcpl_id.
 *
 * \virtual
 *
 * \since 1.10.0
 *
 */
H5_DLL herr_t H5Pget_virtual_count(hid_t dcpl_id, size_t *count/*out*/);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Gets the name of a source dataset used in the mapping
 *
 * \dcpl_id
 * \param[in]  index Mapping index. The value of \p index is 0 (zero) or
 *                   greater and less than \p count
 *                   (0 ≤ \p index < \p count), where \p count is the
 *                   number of mappings returned by H5Pget_virtual_count().
 * \param[out] name  A buffer containing the name of the source dataset
 * \param[in]  size  The size, in bytes, of the name buffer. Must be the
 *                   size of the dataset name in bytes plus 1 for a NULL
 *                   terminator
 *
 * \return Returns the length of the dataset name if successful;
 *         otherwise returns a negative value.
 *
 * \details H5Pget_virtual_dsetname() takes the dataset creation property
 *          list for the virtual dataset, \p dcpl_id, the mapping index,
 *          \p index, the size of the dataset name for a source dataset,
 *          \p size, and retrieves the name of the source dataset used in
 *          the mapping.
 *
 *          Up to \p size characters of the dataset name are returned in
 *          \p name; additional characters, if any, are not returned to
 *          the user application.
 *
 *          If the length of the dataset name, which determines the
 *          required value of \p size, is unknown, a preliminary call
 *          to H5Pget_virtual_dsetname() with the last two parameters
 *          set to NULL and zero respectively can be made. The return
 *          value of this call will be the size in bytes of the dataset
 *          name. That value, plus 1 for a NULL terminator, must then be
 *          assigned to \p size for a second H5Pget_virtual_dsetname()
 *          call, which will retrieve the actual dataset name.
 *
 * \virtual
 *
 * \since 1.10.0
 *
 */
H5_DLL ssize_t H5Pget_virtual_dsetname(hid_t dcpl_id, size_t index,
    char *name/*out*/, size_t size);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Gets the filename of a source dataset used in the mapping
 *
 * \dcpl_id
 * \param[in]  index Mapping index. The value of \p index is 0 (zero) or
 *                   greater and less than \p count
 *                   (0 ≤ \p index < \p count), where \p count is the
 *                   number of mappings returned by H5Pget_virtual_count().
 * \param[out] name  A buffer containing the name of the file containing
 *                   the source dataset
 * \param[in]  size  The size, in bytes, of the name buffer. Must be the
 *                   size of the filename in bytes plus 1 for a NULL
 *                   terminator
 *
 * \return Returns the length of the filename if successful; otherwise
 *         returns a negative value.
 *
 * \details H5Pget_virtual_filename() takes the dataset creation property
 *          list for the virtual dataset, \p dcpl_id, the mapping index,
 *          \p index, the size of the filename for a source dataset,
 *          \p size, and retrieves the name of the file for a source dataset
 *          used in the mapping.
 *
 *          Up to \p size characters of the filename are returned in
 *          \p name; additional characters, if any, are not returned to
 *          the user application.
 *
 *          If the length of the filename, which determines the required
 *          value of \p size, is unknown, a preliminary call to
 *          H5Pget_virtual_filename() with the last two parameters set
 *          to NULL and zero respectively can be made. The return value
 *          of this call will be the size in bytes of the filename. That
 *          value, plus 1 for a NULL terminator, must then be assigned to
 *          \p size for a second H5Pget_virtual_filename() call, which
 *          will retrieve the actual filename.
 *
 * \virtual
 *
 * \since 1.10.0
 *
 */
H5_DLL ssize_t H5Pget_virtual_filename(hid_t dcpl_id, size_t index,
    char *name/*out*/, size_t size);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Gets a dataspace identifier for the selection within the source
 *        dataset used in the mapping
 *
 * \dcpl_id
 * \param[in] index Mapping index. The value of \p index is 0 (zero) or
 *                  greater and less than \p count
 *                  (0 ≤ \p index < \p count), where \p count is the number
 *                  of mappings returned by H5Pget_virtual_count().
 *
 * \return \hid_t{valid dataspace identifier}
 *
 * \details H5Pget_virtual_srcspace() takes the dataset creation property
 *          list for the virtual dataset, \p dcpl_id, and the mapping
 *          index, \p index, and returns a dataspace identifier for the
 *          selection within the source dataset used in the mapping.
 *
 * \virtual
 *
 * \since 1.10.0
 *
 */
H5_DLL hid_t H5Pget_virtual_srcspace(hid_t dcpl_id, size_t index);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Gets a dataspace identifier for the selection within the virtual
 *        dataset used in the mapping
 *
 * \dcpl_id
 * \param[in] index Mapping index. The value of \p index is 0 (zero) or
 *                  greater and less than \p count
 *                  (0 ≤ \p index < \p count), where \p count is the number
 *                  of mappings returned by H5Pget_virtual_count()
 *
 * \return \hid_t{valid dataspace identifier}
 *
 * \details H5Pget_virtual_vspace() takes the dataset creation property
 *          list for the virtual dataset, \p dcpl_id, and the mapping
 *          index, \p index, and returns a dataspace identifier for the
 *          selection within the virtual dataset used in the mapping.
 *
 * \virtual
 *
 * \since 1.10.0
 *
 */
H5_DLL hid_t H5Pget_virtual_vspace(hid_t dcpl_id, size_t index);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Sets the timing for storage space allocation
 *
 * \dcpl_id{plist_id}
 * \param[in] alloc_time When to allocate dataset storage space
 *
 * \return \herr_t
 *
 * \details H5Pset_alloc_time() sets up the timing for the allocation of
 *          storage space for a dataset's raw data. This property is set
 *          in the dataset creation property list \p plist_id. Timing is
 *          specified in \p alloc_time with one of the following values:
 *
 *          <table>
 *           <tr>
 *            <td>#H5D_ALLOC_TIME_DEFAULT</td>
 *            <td>Allocate dataset storage space at the default time<br />
 *                (Defaults differ by storage method.)</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_ALLOC_TIME_EARLY</td>
 *            <td>Allocate all space when the dataset is created<br />
 *            (Default for compact datasets.)</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_ALLOC_TIME_INCR</td>
 *            <td>Allocate space incrementally, as data is written to
 *                the dataset<br />(Default for chunked storage datasets.)
 *
 *                \li Chunked datasets: Storage space allocation for each
 *                    chunk is deferred until data is written to the chunk.
 *                \li Contiguous datasets: Incremental storage space
 *                    allocation for contiguous data is treated as late
 *                    allocation.
 *                \li Compact datasets: Incremental allocation is not
 *                    allowed with compact datasets; H5Pset_alloc_time()
 *                    will return an error.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_ALLOC_TIME_LATE</td>
 *            <td>Allocate all space when data is first written to the
 *                dataset<br />
 *                (Default for contiguous datasets.)</td>
 *           </tr>
 *          </table>
 *
 * \note H5Pset_alloc_time() is designed to work in concert with the
 *       dataset fill value and fill value write time properties, set
 *       with the functions H5Pset_fill_value() and H5Pset_fill_time().
 *
 * \note See H5Dcreate() for further cross-references.
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pset_alloc_time(hid_t plist_id, H5D_alloc_time_t
    alloc_time);
/**
 *-------------------------------------------------------------------------
 * \ingroup DCPL
 *
 * \brief Sets the size of the chunks used to store a chunked layout
 *        dataset
 *
 * \dcpl_id{plist_id}
 * \param[in] ndims  The number of dimensions of each chunk
 * \param[in] dim    An array defining the size, in dataset elements, of
 *                   each chunk
 *
 * \return \herr_t
 * \details H5Pset_chunk() sets the size of the chunks used to store a
 *          chunked layout dataset. This function is only valid for dataset
 *          creation property lists.
 *
 *          The \p ndims parameter currently must be the same size as the
 *          rank of the dataset.
 *
 *          The values of the \p dim array define the size of the chunks
 *          to store the dataset's raw data. The unit of measure for \p dim
 *          values is dataset elements.
 *
 *          As a side-effect of this function, the layout of the dataset is
 *          changed to #H5D_CHUNKED, if it is not already so set.
 *
 * \note Chunk size cannot exceed the size of a fixed-size dataset. For
 *       example, a dataset consisting of a 5x4 fixed-size array cannot be
 *       defined with 10x10 chunks. Chunk maximums:
 *       - The maximum number of elements in a chunk is 2<sup>32</sup>-1 which
 *         is equal to 4,294,967,295. If the number of elements in a chunk is
 *         set via H5Pset_chunk() to a value greater than 2<sup>32</sup>-1,
 *         then H5Pset_chunk() will fail.
 *       - The maximum size for any chunk is 4GB. If a chunk that is larger
 *         than 4GB attempts to be written with H5Dwrite(), then H5Dwrite()
 *         will fail.
 *
 * \see H5Pset_layout(), H5Dwrite()
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_chunk(hid_t plist_id, int ndims, const hsize_t dim[/*ndims*/]);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Sets the edge chunk option in a dataset creation property list
 *
 * \dcpl_id{plist_id}
 * \param[in] opts Edge chunk option flag. Valid values are:
 *                 \li #H5D_CHUNK_DONT_FILTER_PARTIAL_CHUNKS
 *                     When enabled, filters are not applied to partial
 *                     edge chunks. When disabled, partial edge chunks are
 *                     filtered. Enabling this option will improve
 *                     performance when appending to the dataset and, when
 *                     compression filters are used, prevent reallocation
 *                     of these chunks. Datasets created with this option
 *                     enabled will be inaccessible with HDF5 library
 *                     versions before Release 1.10. Default: \e Disabled
 *                 \li 0 (zero) Disables option; partial edge chunks
 *                     will be compressed.
 *
 * \return \herr_t
 *
 * \details H5Pset_chunk_opts() sets the edge chunk option in the
 *          dataset creation property list \p dcpl_id.
 *
 *          The available option is detailed in the parameters section.
 *          Only chunks that are not completely filled by the dataset’s
 *          dataspace are affected by this option. Such chunks are
 *          referred to as partial edge chunks.
 *
 * \note \b Motivation: H5Pset_chunk_opts() is used to specify storage
 *       options for chunks on the edge of a dataset’s dataspace. This
 *       capability allows the user to tune performance in cases where
 *       the dataset size may not be a multiple of the chunk size and
 *       the handling of partial edge chunks can impact performance.
 *
 * \since 1.10.0
 *
 */
H5_DLL herr_t H5Pset_chunk_opts(hid_t plist_id, unsigned opts);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Sets the flag to create minimized dataset object headers
 *
 * \dcpl_id
 * \param[in] minimize Flag for indicating whether or not a dataset's
 *                     object header will be minimized
 *
 * \return \herr_t
 *
 * \details H5Pset_dset_no_attrs_hint() sets the no dataset attributes
 *          hint setting for the dataset creation property list \p dcpl_id.
 *          Datasets created with the dataset creation property list
 *          \p dcpl_id will have their object headers minimized if the
 *          boolean flag \p minimize is set to TRUE. By setting \p minimize
 *          to TRUE, the library expects that no attributes will be added
 *          to the dataset. Attributes can be added, but they are appended
 *          with a continuation message, which can reduce performance.
 *
 *          This setting interacts with H5Fset_dset_no_attrs_hint(): if
 *          either is set to TRUE, then the created dataset's object header
 *          will be minimized.
 *
 * \since 1.10.5
 *
 */
H5_DLL herr_t H5Pset_dset_no_attrs_hint(hid_t dcpl_id, hbool_t minimize);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Adds an external file to the list of external files
 *
 * \dcpl_id{plist_id}
 * \param[in] name   Name of an external file
 * \param[in] offset Offset, in bytes, from the beginning of the file to
 *                   the location in the file where the data starts
 * \param[in] size   Number of bytes reserved in the file for the data
 *
 * \return \herr_t
 *
 * \details The first call to H5Pset_external() sets the external
 *          storage property in the property list, thus designating that
 *          the dataset will be stored in one or more non-HDF5 file(s)
 *          external to the HDF5 file. This call also adds the file
 *          \p name as the first file in the list of external files.
 *          Subsequent calls to the function add the named file as the
 *          next file in the list.
 *
 *          If a dataset is split across multiple files, then the files
 *          should be defined in order. The total size of the dataset is
 *          the sum of the \p size arguments for all the external files.
 *          If the total size is larger than the size of a dataset then
 *          the dataset can be extended (provided the data space also
 *          allows the extending).
 *
 *         The \p size argument specifies the number of bytes reserved
 *         for data in the external file. If \p size is set to
 *         #H5F_UNLIMITED, the external file can be of unlimited size
 *         and no more files can be added to the external files list.
 *         If \p size is set to 0 (zero), no external file will actually
 *         be created.
 *
 *         All of the external files for a given dataset must be specified
 *         with H5Pset_external() before H5Dcreate() is called to create
 *         the dataset. If one these files does not exist on the system
 *         when H5Dwrite() is called to write data to it, the library
 *         will create the file.
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_external(hid_t plist_id, const char *name, off_t offset,
          hsize_t size);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Sets the time when fill values are written to a dataset
 *
 * \dcpl_id{plist_id}
 * \param[in] fill_time When to write fill values to a dataset
 *
 * \return \herr_t
 *
 * \details H5Pset_fill_time() sets up the timing for writing fill values
 *          to a dataset. This property is set in the dataset creation
 *          property list \p plist_id. Timing is specified in \p fill_time
 *          with one of the following values:
 *
 *          <table>
 *           <tr>
 *            <td>#H5D_FILL_TIME_IFSET</td>
 *            <td>Write fill values to the dataset when storage space is
 *                allocated only if there is a user-defined fill value,
 *                i.e.,one set with H5Pset_fill_value(). (Default)</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_FILL_TIME_ALLOC</td>
 *            <td>Write fill values to the dataset when storage space is
 *                allocated.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_FILL_TIME_NEVER</td>
 *            <td>Never write fill values to the dataset.</td>
 *           </tr>
 *          </table>
 *
 * \note H5Pset_fill_time() is designed for coordination with the dataset
 *      fill value and dataset storage allocation time properties, set
 *      with the functions H5Pset_fill_value() and H5Pset_alloc_time().
 *      See H5Dcreate() for further cross-references.
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pset_fill_time(hid_t plist_id, H5D_fill_time_t fill_time);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Sets the fill value for a dataset
 *
 * \dcpl_id{plist_id}
 * \param[in] type_id Datatype of \p value
 * \param[in] value Pointer to buffer containing value to use as
 *            fill value
 *
 * \return \herr_t
 *
 * \details H5Pset_fill_value() sets the fill value for a dataset in the
 *          dataset creation property list. \p value is interpreted as
 *          being of datatype \p type_id. This datatype may differ from
 *          that of the dataset, but the HDF5 library must be able to
 *          convert \p value to the dataset datatype when the dataset is
 *          created.
 *
 *          The default fill value is 0 (zero), which is interpreted
 *          according to the actual dataset datatype.
 *
 *          Setting \p value to NULL indicates that the fill value is to
 *          be undefined.
 *
 * \note Applications sometimes write data only to portions of an allocated
 *       dataset. It is often useful in such cases to fill the unused space
 *       with a known fill value. This function allows the user application
 *       to set that fill value; the functions H5Dfill() and
 *       H5Pset_fill_time(), respectively, provide the ability to apply the
 *       fill value on demand or to set up its automatic application.
 *
 * \note A fill value should be defined so that it is appropriate for the
 *       application. While the HDF5 default fill value is 0 (zero), it is
 *       often appropriate to use another value. It might be useful, for
 *       example, to use a value that is known to be impossible for the
 *       application to legitimately generate.
 *
 * \note H5Pset_fill_value() is designed to work in concert with
 *       H5Pset_alloc_time() and H5Pset_fill_time(). H5Pset_alloc_time()
 *       and H5Pset_fill_time() govern the timing of dataset storage
 *       allocation and fill value write operations and can be important in
 *       tuning application performance.
 *
 * \note See H5Dcreate() for further cross-references.
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_fill_value(hid_t plist_id, hid_t type_id,
     const void *value);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DCPL
 *
 * \brief Sets up use of the shuffle filter
 *
 * \dcpl_id{plist_id}
 *
 * \return \herr_t
 *
 * \details H5Pset_shuffle() sets the shuffle filter, #H5Z_FILTER_SHUFFLE,
 *          in the dataset creation property list \p plist_id. The shuffle
 *          filter de-interlaces a block of data by reordering the bytes.
 *          All the bytes from one consistent byte position of each data
 *          element are placed together in one block; all bytes from a
 *          second consistent byte position of each data element are placed
 *          together a second block; etc. For example, given three data
 *          elements of a 4-byte datatype stored as 012301230123, shuffling
 *          will re-order data as 000111222333. This can be a valuable step
 *          in an effective compression algorithm because the bytes in each
 *          byte position are often closely related to each other and
 *          putting them together can increase the compression ratio.
 *
 *          As implied above, the primary value of the shuffle filter lies
 *          in its coordinated use with a compression filter; it does not
 *          provide data compression when used alone. When the shuffle
 *          filter is applied to a dataset immediately prior to the use of
 *          a compression filter, the compression ratio achieved is often
 *          superior to that achieved by the use of a compression filter
 *          without the shuffle filter.
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pset_shuffle(hid_t plist_id);
/**
 *-------------------------------------------------------------------------
 * \ingroup DCPL
 *
 * \brief Sets the type of storage used to store the raw data for a dataset
 *
 * \dcpl_id{plist_id}
 * \param[in] layout Type of storage layout for raw data
 *
 * \return \herr_t
 * \details H5Pset_layout() sets the type of storage used to store the raw
 *          data for a dataset. This function is only valid for dataset
 *          creation property lists.
 *
 *          Valid values for \p layout are:
 *           - #H5D_COMPACT: Store raw data in the dataset object header
 *                           in file. This should only be used for datasets
 *                           with small amounts of raw data. The raw data
 *                           size limit is 64K (65520 bytes). Attempting
 *                           to create a dataset with raw data larger than
 *                           this limit will cause the H5Dcreate() call to
 *                           fail.
 *           - #H5D_CONTIGUOUS: Store raw data separately from the object
 *                              header in one large chunk in the file.
 *           - #H5D_CHUNKED: Store raw data separately from the object header
 *                           as chunks of data in separate locations in
 *                           the file.
 *           - #H5D_VIRTUAL: Draw raw data from multiple datasets in
 *                           different files.
 *
 *          Note that a compact storage layout may affect writing data to
 *          the dataset with parallel applications. See the note in
 *          H5Dwrite() documentation for details.
 * \version 1.10.0 #H5D_VIRTUAL added in this release.
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_layout(hid_t plist_id, H5D_layout_t layout);
H5_DLL herr_t H5Pset_virtual(hid_t dcpl_id, hid_t vspace_id,
    const char *src_file_name, const char *src_dset_name, hid_t src_space_id);
/**
 *-------------------------------------------------------------------------
 * \ingroup DCPL
 *
 * \brief Sets up use of the SZIP compression filter
 *
 * \dcpl_id{plist_id}
 * \param[in] options_mask A bit-mask conveying the desired SZIP options;
 *                         Valid values are #H5_SZIP_EC_OPTION_MASK and
 *                         #H5_SZIP_NN_OPTION_MASK.
 * \param[in] pixels_per_block The number of pixels or data elements in each
 *            data block
 *
 * \return \herr_t
 *
 * \details H5Pset_szip() sets an SZIP compression filter, #H5Z_FILTER_SZIP,
 *          for a dataset. SZIP is a compression method designed for use with
 *          scientific data.
 *
 *          Before proceeding, all users should review the “Limitations”
 *          section below.
 *
 *          Users familiar with SZIP outside the HDF5 context may benefit
 *          from reviewing the Note “For Users Familiar with SZIP in Other
 *          Contexts” below.
 *
 *          In the text below, the term pixel refers to an HDF5 data element.
 *          This terminology derives from SZIP compression's use with image
 *          data, where pixel referred to an image pixel.
 *
 *          The SZIP \p bits_per_pixel value (see Note, below) is automatically
 *          set, based on the HDF5 datatype. SZIP can be used with atomic
 *          datatypes that may have size of 8, 16, 32, or 64 bits.
 *          Specifically, a dataset with a datatype that is 8-, 16-, 32-, or
 *          64-bit signed or unsigned integer; char; or 32- or 64-bit float
 *          can be compressed with SZIP. See Note, below, for further
 *          discussion of the the SZIP \p bits_per_pixel setting.
 *
 *          SZIP options are passed in an options mask, \p options_mask,
 *          as follows.
 *
 *          <table>
 *            <tr>
 *             <th>Option</th>
 *             <th>Description (Mutually exclusive; select one.)</th>
 *            </tr>
 *            <tr>
 *             <td>#H5_SZIP_EC_OPTION_MASK</td>
 *             <td>Selects entropy coding method</td>
 *            </tr>
 *            <tr>
 *             <td>#H5_SZIP_NN_OPTION_MASK</td>
 *             <td>Selects nearest neighbor coding method</td>
 *            </tr>
 *           </table>
 *
 *           The following guidelines can be used in determining which
 *           option to select:
 *
 *           - The entropy coding method, the EC option specified by
 *             #H5_SZIP_EC_OPTION_MASK, is best suited for data that has been
 *             processed. The EC method works best for small numbers.
 *           - The nearest neighbor coding method, the NN option specified
 *             by #H5_SZIP_NN_OPTION_MASK, preprocesses the data then the
 *             applies EC method as above.
 *
 *           Other factors may affect results, but the above criteria
 *           provides a good starting point for optimizing data compression.
 *
 *           SZIP compresses data block by block, with a user-tunable block
 *           size. This block size is passed in the parameter
 *           \p pixels_per_block and must be even and not greater than 32,
 *           with typical values being 8, 10, 16, or 32. This parameter
 *           affects compression ratio; the more pixel values vary, the
 *           smaller this number should be to achieve better performance.
 *
 *           In HDF5, compression can be applied only to chunked datasets.
 *           If \p pixels_per_block is bigger than the total number of
 *           elements in a dataset chunk, H5Pset_szip() will succeed but
 *           the subsequent call to H5Dcreate() will fail; the conflict
 *           can be detected only when the property list is used.
 *
 *           To achieve optimal performance for SZIP compression, it is
 *           recommended that a chunk's fastest-changing dimension be equal
 *           to N times \p pixels_per_block where N is the maximum number of
 *           blocks per scan line allowed by the SZIP library. In the
 *           current version of SZIP, N is set to 128.
 *
 *           SZIP compression is an optional HDF5 filter.
 *
 *           \b Limitations:
 *
 *           - SZIP compression cannot be applied to compound, array,
 *             variable-length, enumeration, or any other user-defined
 *             datatypes. If an SZIP filter is set in a dataset creation
 *             property list used to create a dataset containing a
 *             non-allowed datatype, the call to H5Dcreate() will fail; the
 *             conflict can be detected only when the property list is used.
 *           - Users should be aware that there are factors that affect one’s
 *             rights and ability to use SZIP compression by reviewing the
 *             SZIP copyright notice.
 *
 * \note \b For \b Users \b Familiar \b with \b SZIP \b in \b Other \b Contexts:
 *
 * \note  The following notes are of interest primarily to those who have
 *        used SZIP compression outside of the HDF5 context.
 *        In non-HDF5 applications, SZIP typically requires that the user
 *        application supply additional parameters:
 *        - \p pixels_in_object, the number of pixels in the object to
 *          be compressed
 *        - \p bits_per_pixel, the number of bits per pixel
 *        - \p pixels_per_scanline, the number of pixels per scan line
 *
 * \note  These values need not be independently supplied in the HDF5
 *        environment as they are derived from the datatype and dataspace,
 *        which are already known. In particular, HDF5 sets
 *        \p pixels_in_object to the number of elements in a chunk and
 *        \p bits_per_pixel to the size of the element or pixel datatype.
 *
 * \note  The following algorithm is used to set \p pixels_per_scanline:
 *        - If the size of a chunk's fastest-changing dimension, size,
 *          is greater than 4K, set \p pixels_per_scanline to 128 times
 *          \p pixels_per_block.
 *        - If size is less than 4K but greater than \p pixels_per_block,
 *          set \p pixels_per_scanline to the minimum of size and 128
 *          times \p pixels_per_block.
 *        - If size is less than \p pixels_per_block but greater than the
 *          number elements in the chunk, set \p pixels_per_scanline to
 *          the minimum of the number elements in the chunk and 128 times
 *          \p pixels_per_block.
 *
 * \note  The HDF5 datatype may have precision that is less than the full
 *        size of the data element, e.g., an 11-bit integer can be defined
 *        using H5Tset_precision(). To a certain extent, SZIP can take
 *        advantage of the precision of the datatype to improve compression:
 *        - If the HDF5 datatype size is 24-bit or less and the offset of
 *          the bits in the HDF5 datatype is zero (see H5Tset_offset() or
 *          H5Tget_offset()), the data is the in lowest N bits of the data
 *          element. In this case, the SZIP \p bits_per_pixel is set to the
 *          precision of the HDF5 datatype.
 *        - If the offset is not zero, the SZIP \p bits_per_pixel will be
 *          set to the number of bits in the full size of the data element.
 *        - If the HDF5 datatype precision is 25-bit to 32-bit, the SZIP
 *          \p bits_per_pixel will be set to 32.
 *        - If the HDF5 datatype precision is 33-bit to 64-bit, the SZIP
 *          \p bits_per_pixel will be set to 64.
 *
 * \note HDF5 always modifies the options mask provided by the user to set up
 *       usage of RAW_OPTION_MASK, ALLOW_K13_OPTION_MASK, and one of
 *       LSB_OPTION_MASK or MSB_OPTION_MASK, depending on endianness of the
 *       datatype.
 *
 * \since 1.6.0
 *
 *--------------------------------------------------------------------------
 */
H5_DLL herr_t H5Pset_szip(hid_t plist_id, unsigned options_mask, unsigned pixels_per_block);
H5_DLL herr_t H5Pset_nbit(hid_t plist_id);
H5_DLL herr_t H5Pset_scaleoffset(hid_t plist_id, H5Z_SO_scale_type_t scale_type, int scale_factor);

/* Dataset access property list (DAPL) routines */
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DAPL
 *
 * \brief Retrieves the values of the append property that is set up in
 *        the dataset access property list
 *
 * \dapl_id
 * \param[in] dims     The number of elements for \p boundary
 * \param[in] boundary The dimension sizes used to determine the boundary
 * \param[in] func     The user-defined callback function
 * \param[in] udata    The user-defined input data
 *
 * \return \herr_t
 *
 * \details H5Pget_append_flush() obtains the following information
 *          from the dataset access property list, \p dapl_id.
 *
 *          \p boundary consists of the sizes set up in the access
 *          property list that are used to determine when a dataset
 *          dimension size hits the boundary. Only at most \p dims
 *          boundary sizes are retrieved, and \p dims will not exceed
 *          the corresponding value that is set in the property list.
 *
 *          \p func is the user-defined callback function to invoke when
 *          a dataset’s appended dimension size reaches a boundary and
 *          \p udata is the user-defined input data for the callback
 *          function.
 *
 * \todo Example Usage was removed and needs to be re-added
 *
 * \since 1.10.0
 *
 */
H5_DLL herr_t H5Pget_append_flush(hid_t dapl_id, unsigned dims,
    hsize_t boundary[], H5D_append_cb_t *func, void **udata);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DAPL
 *
 * \brief Retrieves the raw data chunk cache parameters
 *
 * \dapl_id
 * \param[out] rdcc_nslots Number of chunk slots in the raw data chunk
 *                         cache hash table
 * \param[out] rdcc_nbytes Total size of the raw data chunk cache, in
 *                         bytes
 * \param[out] rdcc_w0     Preemption policy
 *
 * \return \herr_t
 *
 * \details H5Pget_chunk_cache() retrieves the number of chunk slots in
 *          the raw data chunk cache hash table, the maximum possible
 *          number of bytes in the raw data chunk cache, and the
 *          preemption policy value.
 *
 *          These values are retrieved from a dataset access property
 *          list. If the values have not been set on the property list,
 *          then values returned will be the corresponding values from
 *          a default file access property list.
 *
 *          Any (or all) pointer arguments may be null pointers, in which
 *          case the corresponding data is not returned.
 *
 * \since 1.8.3
 *
 */
H5_DLL herr_t H5Pget_chunk_cache(hid_t dapl_id,
       size_t *rdcc_nslots/*out*/,
       size_t *rdcc_nbytes/*out*/,
       double *rdcc_w0/*out*/);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DAPL
 *
 * \brief Retrieves the prefix for external raw data storage files as set
 *        in the dataset access property list
 *
 * \dapl_id
 * \param[in,out] prefix Dataset external storage prefix in UTF-8 or
 *                       ASCII (\em Path and \em filename must be ASCII
 *                       on Windows systems.)
 * \param[in]     size   Size of prefix buffer in bytes
 *
 * \return Returns the size of \p prefix and the prefix string will be
 *         stored in \p prefix if successful.
 *         Otherwise returns a negative value and the contents of \p prefix
 *         will be undefined.
 *
 * \details H5Pget_efile_prefix() retrieves the file system path prefix
 *          for locating external files associated with a dataset that
 *          uses external storage. This will be the value set with
 *          H5Pset_efile_prefix() or the HDF5 library’s default.
 *
 *          The value of \p size is the size in bytes of the prefix,
 *          including the NULL terminator. If the size is unknown, a
 *          preliminary H5Pget_elink_prefix() call with the pointer
 *          \p prefix set to NULL will return the size of the prefix
 *          without the NULL terminator.
 *
 *          The \p prefix buffer must be allocated by the caller. In a
 *          call that retrieves the actual prefix, that buffer must be
 *          of the size specified in \p size.
 *
 * \note See H5Pset_efile_prefix() for a more complete description of
 *       file location behavior and for notes on the use of the
 *       HDF5_EXTFILE_PREFIX environment variable.
 *
 * \since 1.10.0, 1.8.17
 *
 */
H5_DLL ssize_t H5Pget_efile_prefix(hid_t dapl_id, char* prefix /*out*/, size_t size);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DAPL
 *
 * \brief Retrieves prefix applied to VDS source file paths
 *
 * \dapl_id
 * \param[out] prefix Prefix applied to VDS source file paths
 * \param[in]  size   Size of prefix, including null terminator
 *
 * \return If successful, returns a non-negative value specifying the size
 *         in bytes of the prefix without the NULL terminator; otherwise
 *         returns a negative value.
 *
 * \details H5Pget_virtual_prefix() retrieves the prefix applied to the
 *          path of any VDS source files traversed.
 *
 *          When an VDS source file is traversed, the prefix is retrieved
 *          from the dataset access property list \p dapl_id, returned
 *          in the user-allocated buffer pointed to by \p prefix, and
 *          prepended to the filename stored in the VDS virtual file, set
 *          with H5Pset_virtual().
 *
 *          The size in bytes of the prefix, including the NULL terminator,
 *          is specified in \p size. If \p size is unknown, a preliminary
 *          H5Pget_virtual_prefix() call with the pointer \p prefix set to
 *          NULL will return the size of the prefix without the NULL
 *          terminator.
 *
 * \virtual
 *
 * \since 1.10.2
 *
 */
H5_DLL ssize_t H5Pget_virtual_prefix(hid_t dapl_id, char* prefix /*out*/, size_t size);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DAPL
 *
 * \brief Retrieves prefix applied to VDS source file paths
 *
 * \dapl_id
 * \param[out] gap_size Maximum number of the files and/or datasets
 *                      allowed to be missing for determining the extent
 *                      of an unlimited virtual dataset with printf-style
 *                      mappings. (\em Default: 0)
 *
 * \return \herr_t
 *
 * \details H5Pget_virtual_printf_gap() returns the maximum number of
 *          missing printf-style files and/or datasets for determining the
 *          extent of an unlimited virtual dataaset, \p gap_size, using
 *          the access property list for the virtual dataset, \p dapl_id.
 *
 * The default library value for gap_size is 0 (zero).
 *
 * \since 1.10.0
 *
 */
H5_DLL herr_t H5Pget_virtual_printf_gap(hid_t dapl_id, hsize_t *gap_size);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DAPL
 *
 * \brief Retrieves the view of a virtual dataset accessed with
 *        \p dapl_id
 *
 * \dapl_id
 * \param[out] view The flag specifying the view of the virtual dataset.
 *                  Valid values are:
 *                  \li #H5D_VDS_FIRST_MISSING
 *                  \li #H5D_VDS_LAST_AVAILABLE
 *
 * \return \herr_t
 *
 * \details H5Pget_virtual_view() takes the virtual dataset access property
 *          list, \p dapl_id, and retrieves the flag, \p view, set by the
 *          H5Pset_virtual_view() call.
 *
 * \virtual
 *
 * \since 1.10.0
 *
 */
H5_DLL herr_t H5Pget_virtual_view(hid_t dapl_id, H5D_vds_view_t *view);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DAPL
 *
 * \brief Sets two actions to perform when the size of a dataset’s
 *        dimension being appended reaches a specified boundary
 *
 * \dapl_id
 * \param[in] ndims    The number of elements for boundary
 * \param[in] boundary The dimension sizes used to determine the boundary
 * \param[in] func     The user-defined callback function
 * \param[in] udata    The user-defined input data
 *
 * \return \herr_t
 *
 * \details H5Pset_append_flush() sets the following two actions to
 *          perform for a dataset associated with the dataset access
 *          property list \p dapl_id:
 *
 *          \li Call the callback function \p func set in the property
 *              list
 *          \li Flush the dataset associated with the dataset access
 *              property list
 *
 *          When a user is appending data to a dataset via H5DOappend()
 *          and the dataset’s newly extended dimension size hits a
 *          specified boundary, the library will perform the first action
 *          listed above. Upon return from the callback function, the
 *          library will then perform the second action listed above and
 *          return to the user. If no boundary is hit or set, the two
 *          actions above are not invoked.
 *
 *          The specified boundary is indicated by the parameter
 *          \p boundary. It is a 1-dimensional array with \p ndims
 *          elements, which should be the same as the rank of the
 *          dataset’s dataspace. While appending to a dataset along a
 *          particular dimension index via H5DOappend(), the library
 *          determines a boundary is reached when the resulting dimension
 *          size is divisible by \p boundary[index]. A zero value for
 *          \p boundary[index] indicates no boundary is set for that
 *          dimension index.
 *
 *          The setting of this property will apply only for a chunked
 *          dataset with an extendible dataspace. A dataspace is extendible
 *          when it is defined with either one of the following:
 *
 *          \li A dataspace with fixed current and maximum dimension sizes
 *          \li A dataspace with at least one unlimited dimension for its
 *              maximum dimension size
 *
 *          When creating or opening a chunked dataset, the library will
 *          check whether the boundary as specified in the access property
 *          list is set up properly. The library will fail the dataset
 *          create or open if the following conditions are true:
 *
 *          \li \p ndims, the number of elements for boundary, is not the
 *              same as the rank of the dataset’s dataspace.
 *          \li A non-zero boundary value is specified for a non-extendible
 *          dimension.
 *
 *          The callback function \p func must conform to the following
 *          prototype:
 *          \Code{typedef herr_t (#H5D_append_cb_t)(hid_t dataset_id,
 *                                    hsize_t *cur_dims, void *user_data)}
 *
 *          The parameters of the callback function, per the above
 *          prototype, are defined as follows:
 *
 *          \li \p dataset_id is the dataset identifier.
 *          \li \p cur_dims is the dataset’s current dimension sizes when
 *              a boundary is hit.
 *          \li \p user_data is the user-defined input data.
 *
 * \todo Example Usage was removed and should be added back.
 * \todo Adding snippet for H5D_append_cb_t_snip did not work.
 * \todo H5DOappend() not found
 *
 * \since 1.10.0
 *
 */
H5_DLL herr_t H5Pset_append_flush(hid_t dapl_id, unsigned ndims,
    const hsize_t boundary[], H5D_append_cb_t func, void *udata);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DAPL
 *
 * \brief Sets the raw data chunk cache parameters
 *
 * \dapl_id
 * \param[in] rdcc_nslots The number of chunk slots in the raw data chunk
 *                        cache for this dataset. Increasing this value
 *                        reduces the number of cache collisions, but
 *                        slightly increases the memory used. Due to the
 *                        hashing strategy, this value should ideally be a
 *                        prime number. As a rule of thumb, this value
 *                        should be at least 10 times the number of chunks
 *                        that can fit in \p rdcc_nbytes bytes. For maximum
 *                        performance, this value should be set
 *                        approximately 100 times that number of chunks.
 *                        The default value is 521. If the value passed is
 *                        #H5D_CHUNK_CACHE_NSLOTS_DEFAULT, then the
 *                        property will not be set on \p dapl_id and the
 *                        parameter will come from the file access
 *                        property list used to open the file.
 * \param[in] rdcc_nbytes The total size of the raw data chunk cache for
 *                        this dataset. In most cases increasing this
 *                        number will improve performance, as long as
 *                        you have enough free memory.
 *                        The default size is 1 MB. If the value passed is
 *                        #H5D_CHUNK_CACHE_NBYTES_DEFAULT, then the
 *                        property will not be set on \p dapl_id and the
 *                        parameter will come from the file access
 *                        property list.
 * \param[in] rdcc_w0     The chunk preemption policy for this dataset.
 *                        This must be between 0 and 1 inclusive and
 *                        indicates the weighting according to which chunks
 *                        which have been fully read or written are
 *                        penalized when determining which chunks to flush
 *                        from cache. A value of 0 means fully read or
 *                        written chunks are treated no differently than
 *                        other chunks (the preemption is strictly LRU)
 *                        while a value of 1 means fully read or written
 *                        chunks are always preempted before other chunks.
 *                        If your application only reads or writes data
 *                        once, this can be safely set to 1. Otherwise,
 *                        this should be set lower, depending on how often
 *                        you re-read or re-write the same data.
 *                        The default value is 0.75. If the value passed is
 *                        #H5D_CHUNK_CACHE_W0_DEFAULT, then the property
 *                        will not be set on \p dapl_id and the parameter
 *                        will come from the file access property list.
 *
 * \return \herr_t
 *
 * \details H5Pset_chunk_cache() sets the number of elements, the total
 *          number of bytes, and the preemption policy value in the raw
 *          data chunk cache on a dataset access property list. After
 *          calling this function, the values set in the property list
 *          will override the values in the file's file access property
 *          list.
 *
 *          The raw data chunk cache inserts chunks into the cache
 *          by first computing a hash value using the address of a chunk,
 *          then using that hash value as the chunk's index into the table
 *          of cached chunks. The size of this hash table, i.e., and the
 *          number of possible hash values, is determined by the
 *          \p rdcc_nslots parameter. If a different chunk in the cache
 *          has the same hash value, this causes a collision, which
 *          reduces efficiency. If inserting the chunk into cache would
 *          cause the cache to be too big, then the cache is pruned
 *          according to the \p rdcc_w0 parameter.
 *
 * \note \b Motivation: H5Pset_chunk_cache() is used to adjust the chunk
 *       cache parameters on a per-dataset basis, as opposed to a global
 *       setting for the file using H5Pset_cache(). The optimum chunk
 *       cache parameters may vary widely with different data layout and
 *       access patterns, so for optimal performance they must be set
 *       individually for each dataset. It may also be beneficial to
 *       reduce the size of the chunk cache for datasets whose
 *       performance is not important in order to save memory space.
 *
 * \note \b Example \b Usage: The following code sets the chunk cache to
 *       use a hash table with 12421 elements and a maximum size of
 *       16 MB, while using the preemption policy specified for the
 *       entire file:
 *       \Code{
 *       H5Pset_chunk_cache(dapl_id, 12421, 16*1024*1024,
 *            H5D_CHUNK_CACHE_W0_DEFAULT);}
 *
 * \note \b Usage \b Notes: The chunk cache size is a property for
 *       accessing a dataset and is not stored with a dataset or a
 *       file. To guarantee the same chunk cache settings each time
 *       the dataset is opened, call H5Dopen() with a dataset access
 *       property list where the chunk cache size is set by calling
 *       H5Pset_chunk_cache() for that property list. The property
 *       list can be used for multiple accesses in the same
 *       application.
 *
 * \note For files where the same chunk cache size will be
 *       appropriate for all or most datasets, H5Pset_cache() can
 *       be called with a file access property list to set the
 *       chunk cache size for accessing all datasets in the file.
 *
 * \note Both methods can be used in combination, in which case
 *       the chunk cache size set by H5Pset_cache() will apply
 *       except for specific datasets where H5Dopen() is called
 *       with dataset property list with the chunk cache size
 *       set by H5Pset_chunk_cache().
 *
 * \note In the absence of any cache settings, H5Dopen() will
 *       by default create a 1 MB chunk cache for the opened
 *       dataset. If this size happens to be appropriate, no
 *       call will be needed to either function to set the
 *       chunk cache size.
 *
 * \note It is also possible that a change in access pattern
 *       for later access to a dataset will change the
 *       appropriate chunk cache size.
 *
 * \since 1.8.3
 *
 */
H5_DLL herr_t H5Pset_chunk_cache(hid_t dapl_id, size_t rdcc_nslots,
       size_t rdcc_nbytes, double rdcc_w0);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DAPL
 *
 * \brief Sets the external dataset storage file prefix in the dataset
 *        access property list
 *
 * \dapl_id
 * \param[in] prefix Dataset external storage prefix in UTF-8 or ASCII
 *           (<em>Path and filename must be ASCII on Windows systems.</em>)
 *
 * \return \herr_t
 *
 * \details H5Pset_efile_prefix() sets the prefix used to locate raw data
 *          files for a dataset that uses external storage. This prefix
 *          can provide either an absolute path or a relative path to the
 *          external files.
 *
 *          H5Pset_efile_prefix() is used in conjunction with
 *          H5Pset_external() to control the behavior of the HDF5 library
 *          when searching for the raw data files associated with a dataset
 *          that uses external storage:
 *
 *          \li The default behavior of the library is to search for the
 *              dataset’s external storage raw data files in the same
 *              directory as the HDF5 file which contains the dataset.
 *          \li If the prefix is set to an absolute path, the target
 *              directory will be searched for the dataset’s external
 *              storage raw data files.
 *          \li If the prefix is set to a relative path, the target
 *              directory, relative to the current working directory, will
 *              be searched for the dataset’s external storage raw data
 *              files.
 *          \li If the prefix is set to a relative path that begins with
 *              the special token ${ORIGIN}, that directory, relative to
 *              the HDF5 file containing the dataset, will be searched for
 *              the dataset’s external storage raw data files.
 *
 *           The HDF5_EXTFILE_PREFIX environment variable can be used to
 *           override the above behavior (the environment variable
 *           supersedes the API call). Setting the variable to a path
 *           string and calling H5Dcreate() or H5Dopen() is the equivalent
 *           of calling H5Pset_efile_prefix() and calling the same create
 *           or open function. The environment variable is checked at the
 *           time of the create or open action and copied so it can be
 *           safely changed after the H5Dcreate() or H5Dopen() call.
 *
 *           Calling H5Pset_efile_prefix() with \p prefix set to NULL or
 *           the empty string returns the search path to the default. The
 *           result would be the same as if H5Pset_efile_prefix() had never
 *           been called.
 *
 * \note If the external file prefix is not an absolute path and the HDF5
 *       file is moved, the external storage files will also need to be
 *       moved so they can be accessed at the new location.
 *
 *       As stated above, the use of the HDF5_EXTFILE_PREFIX environment
 *       variable overrides any property list setting.
 *       H5Pset_efile_prefix() and H5Pget_efile_prefix(), being property
 *       functions, set and retrieve only the property list setting; they
 *       are unaware of the environment variable.
 *
 *       On Windows, the prefix must be an ASCII string since the Windows
 *       standard C library’s I/O functions cannot handle UTF-8 file names.
 *
 * \since 1.10.0, 1.8.17
 *
 */
H5_DLL herr_t H5Pset_efile_prefix(hid_t dapl_id, const char* prefix);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DAPL
 *
 * \brief Sets prefix to be applied to VDS source file paths
 *
 * \dapl_id
 * \param[in] prefix Prefix to be applied to VDS source file paths
 *
 * \return \herr_t
 *
 * \details H5Pset_virtual_prefix() sets the prefix to be applied to the
 *          path of any VDS source files traversed. The prefix is prepended
 *          to the filename stored in the VDS virtual file, set with
 *          H5Pset_virtual().
 *
 *          The prefix is specified in the user-allocated buffer \p prefix
 *          and set in the dataset access property list \p dapl_id. The
 *          buffer should not be freed until the property list has been
 *          closed.
 *
 * \virtual
 *
 * \since 1.10.2
 *
 */
H5_DLL herr_t H5Pset_virtual_prefix(hid_t dapl_id, const char* prefix);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DAPL
 *
 * \brief Sets the maximum number of missing source files and/or datasets
 *        with the printf-style names when getting the extent of an
 *        unlimited virtual dataset
 *
 * \dapl_id
 * \param[in] gap_size Maximum number of files and/or datasets allowed to
 *                     be missing for determining the extent of an
 *                     unlimited virtual dataset with printf-style
 *                     mappings (<em>Default value</em>: 0)
 *
 * \return \herr_t
 *
 * \details H5Pset_virtual_printf_gap() sets the access property list for
 *          the virtual dataset, \p dapl_id, to instruct the library to
 *          stop looking for the mapped data stored in the files and/or
 *          datasets with the printf-style names after not finding
 *          \p gap_size files and/or datasets. The found source files and
 *          datasets will determine the extent of the unlimited virtual
 *          dataset with the printf-style mappings.
 *
 *          Consider the following examples where the regularly spaced
 *          blocks of a virtual dataset are mapped to datasets with the
 *          names d-1, d-2, d-3, ..., d-N, ... :
 *
 *          \li If the dataset d-2 is missing and \p gap_size is set to 0,
 *              then the virtual dataset will contain only data found
 *              in d-1.
 *          \li If d-2 and d-3 are missing and \p gap_size is set to 2,
 *              then the virtual dataset will contain the data from
 *              d-1, d-3, ..., d-N, ... .  The blocks that are mapped to
 *              d-2 and d-3 will be filled according to the virtual
 *              dataset’s fill value setting.
 *
 * \virtual
 *
 * \since 1.10.0
 *
 */
H5_DLL herr_t H5Pset_virtual_printf_gap(hid_t dapl_id, hsize_t gap_size);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DAPL
 *
 * \brief Sets the view of the virtual dataset (VDS) to include or exclude
 *        missing mapped elements
 *
 * \dapl_id
 * \param[in] view Flag specifying the extent of the data to be included
 *                 in the view. Valid values are:
 *                 \li #H5D_VDS_FIRST_MISSING: View includes all data
 *                     before the first missing mapped data
 *                 \li #H5D_VDS_LAST_AVAILABLE View includes all
 *                     available mapped data
 *
 * \return \herr_t
 *
 * \details H5Pset_virtual_view() takes the access property list for the
 *          virtual dataset, \p dapl_id, and the flag, \p view, and sets
 *          the VDS view according to the flag value.
 *
 *          If \p view is set to #H5D_VDS_FIRST_MISSING, the view includes
 *          all data before the first missing mapped data. This setting
 *          provides a view containing only the continuous data starting
 *          with the dataset’s first data element. Any break in
 *          continuity terminates the view.
 *
 *          If \p view is set to #H5D_VDS_LAST_AVAILABLE, the view
 *          includes all available mapped data.
 *
 *          Missing mapped data is filled with the fill value set in the
 *          VDS creation property list.
 *
 * \virtual
 *
 * \since 1.10.0
 *
 */
H5_DLL herr_t H5Pset_virtual_view(hid_t dapl_id, H5D_vds_view_t view);

/* Dataset xfer property list (DXPL) routines */
H5_DLL herr_t H5Pget_btree_ratios(hid_t plist_id, double *left/*out*/,
       double *middle/*out*/,
       double *right/*out*/);
H5_DLL size_t H5Pget_buffer(hid_t plist_id, void **tconv/*out*/,
        void **bkg/*out*/);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DXPL
 *
 * \brief Retrieves a data transform expression
 *
 * \param[in]  plist_id   Identifier of the property list or class
 * \param[out] expression Pointer to memory where the transform expression
 *                        will be copied
 * \param[in]  size       Number of bytes of the transform expression to copy to
 *
 * \return Returns the size of the transform expression if successful;
 *         otherwise returns a negative value.
 *
 * \details H5Pget_data_transform() retrieves the data transform
 *          expression previously set in the dataset transfer property
 *          list \p plist_id by H5Pset_data_transform().
 *
 *          H5Pget_data_transform() can be used to both retrieve the
 *          transform expression and to query its size.
 *
 *          If \p expression is non-NULL, up to \p size bytes of the data
 *          transform expression are written to the buffer. If
 *          \p expression is NULL, \p size is ignored and the function
 *          does not write anything to the buffer. The function always
 *          returns the size of the data transform expression.
 *
 *          If 0 is returned for the size of the expression, no data
 *          transform expression exists for the property list.
 *
 *          If an error occurs, the buffer pointed to by \p expression is
 *          unchanged and the function returns a negative value.
 *
 * \since 1.8.0
 *
 */
H5_DLL ssize_t H5Pget_data_transform(hid_t plist_id, char* expression /*out*/, size_t size);
H5_DLL H5Z_EDC_t H5Pget_edc_check(hid_t plist_id);
H5_DLL herr_t H5Pget_hyper_vector_size(hid_t fapl_id, size_t *size/*out*/);
H5_DLL int H5Pget_preserve(hid_t plist_id);
H5_DLL herr_t H5Pget_type_conv_cb(hid_t dxpl_id, H5T_conv_except_func_t *op, void** operate_data);
H5_DLL herr_t H5Pget_vlen_mem_manager(hid_t plist_id,
                                       H5MM_allocate_t *alloc_func,
                                       void **alloc_info,
                                       H5MM_free_t *free_func,
                                       void **free_info);
H5_DLL herr_t H5Pset_btree_ratios(hid_t plist_id, double left, double middle,
       double right);
H5_DLL herr_t H5Pset_buffer(hid_t plist_id, size_t size, void *tconv,
        void *bkg);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup DXPL
 *
 * \brief Sets a data transform expression
 *
 * \param[in] plist_id   Identifier of the property list or class
 * \param[in] expression Pointer to the null-terminated data transform
 *                       expression
 *
 * \return \herr_t
 *
 * \details H5Pset_data_transform() sets the data transform to be used for
 *          reading and writing data. This function operates on the dataset
 *          transfer property list \p plist_id.
 *
 *          The \p expression parameter is a string containing an algebraic
 *          expression, such as (5/9.0)*(x-32) or x*(x-5). When a dataset
 *          is read or written with this property list, the transform
 *          expression is applied with the x being replaced by the values
 *          in the dataset. When reading data, the values in the file are
 *          not changed and the transformed data is returned to the user.
 *
 *          Data transforms can only be applied to integer or
 *          floating-point datasets. Order of operations is obeyed and
 *          the only supported operations are +, -, *, and /. Parentheses
 *          can be nested arbitrarily and can be used to change precedence.
 *          When writing data back to the dataset, the transformed data is
 *          written to the file and there is no way to recover the original
 *          values to which the transform was applied.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_data_transform(hid_t plist_id, const char* expression);
H5_DLL herr_t H5Pset_edc_check(hid_t plist_id, H5Z_EDC_t check);
H5_DLL herr_t H5Pset_filter_callback(hid_t plist_id, H5Z_filter_func_t func,
                                     void* op_data);
H5_DLL herr_t H5Pset_hyper_vector_size(hid_t fapl_id, size_t size);
H5_DLL herr_t H5Pset_preserve(hid_t plist_id, hbool_t status);
H5_DLL herr_t H5Pset_type_conv_cb(hid_t dxpl_id, H5T_conv_except_func_t op, void* operate_data);
H5_DLL herr_t H5Pset_vlen_mem_manager(hid_t plist_id,
                                       H5MM_allocate_t alloc_func,
                                       void *alloc_info, H5MM_free_t free_func,
                                       void *free_info);
#ifdef H5_HAVE_PARALLEL
H5_DLL herr_t H5Pget_mpio_actual_chunk_opt_mode(hid_t plist_id, H5D_mpio_actual_chunk_opt_mode_t *actual_chunk_opt_mode);
H5_DLL herr_t H5Pget_mpio_actual_io_mode(hid_t plist_id, H5D_mpio_actual_io_mode_t *actual_io_mode);
H5_DLL herr_t H5Pget_mpio_no_collective_cause(hid_t plist_id, uint32_t *local_no_collective_cause, uint32_t *global_no_collective_cause);
#endif /* H5_HAVE_PARALLEL */

/* Link creation (LCPL) and String Creation (STRCPL) property list routines */

/**
 *-------------------------------------------------------------------------
 *
 * \ingroup ALCAPL
 *
 * \brief  Retrieves the character encoding used to create a link or
 *         attribute name
 *
 * \param[in]  plist_id  Link creation or attribute creation property list
 *                       identifier
 * \param[out] encoding  String encoding character set
 *
 * \return \herr_t
 *
 * \details H5Pget_char_encoding() retrieves the character encoding used
 *          to encode link or attribute names that are created with the
 *          property list \p plist_id.
 *
 *          Valid values for \p encoding are defined in H5Tpublic.h and
 *          include the following:
 *
 * \csets
 *
 * \note H5Pget_char_encoding() retrieves the character set used for an
 *       HDF5 link or attribute name while H5Tget_cset() retrieves the
 *       character set used in a character or string datatype.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_char_encoding(hid_t plist_id, H5T_cset_t *encoding /*out*/);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup ALCAPL
 *
 * \brief Determines whether property is set to enable creating missing
 *        intermediate groups
 *
 * \lcpl_id{plist_id}
 * \param[out] crt_intmd Flag specifying whether to create intermediate
 *                       groups upon creation of an object
 *
 * \return \herr_t
 *
 * \details H5Pget_create_intermediate_group() determines whether the link
 *          creation property list \p plist_id is set to allow functions
 *          that create objects in groups different from the current
 *          working group to create intermediate groups that may be
 *          missing in the path of a new or moved object.
 *
 *          Functions that create objects in or move objects to a group
 *          other than the current working group make use of this
 *          property. H5Gcreate_anon() and H5Lmove() are examples of such
 *          functions.
 *
 *          If \p crt_intmd is positive, missing intermediate groups will
 *          be created; if \p crt_intmd is non-positive, missing intermediate
 *          groups will not be created.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_create_intermediate_group(hid_t plist_id, unsigned *crt_intmd /*out*/);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup ALCAPL
 *
 * \brief Sets the character encoding used to encode link and attribute
 *        names
 *
 * \param[in] plist_id Link creation or attribute creation property list
 *                     identifier
 * \param[in] encoding String encoding character set
 *
 * \return \herr_t
 *
 * \details H5Pset_char_encoding() sets the character encoding used for
 *          the names of links (which provide the names by which objects
 *          are referenced) or attributes created with the property list
 *          \p plist_id.
 *
 *           Valid values for encoding include the following:
 * \csets
 * \details For example, if the character set for the property list
 *          \p plist_id is set to #H5T_CSET_UTF8, link names pointing to
 *          objects created with the link creation property list
 *          \p plist_id will be encoded using the UTF-8 character set.
 *          Similarly, names of attributes created with the attribute
 *          creation property list \p plist_id will be encoded as UTF-8.
 *
 *          ASCII and UTF-8 Unicode are the only currently supported
 *          character encodings. Extended ASCII encodings (for example,
 *          ISO 8859) are not supported. This encoding policy is not
 *          enforced by the HDF5 library. Using encodings other than
 *          ASCII and UTF-8 can lead to compatibility and usability
 *          problems.
 *
 * \note H5Pset_char_encoding() sets the character set used for an
 *       HDF5 link or attribute name while H5Tset_cset() sets the
 *       character set used in a character or string datatype.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_char_encoding(hid_t plist_id, H5T_cset_t encoding);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup ALCAPL
 *
 * \brief Specifies in property list whether to create missing
 *        intermediate groups
 *
 * \lcpl_id{plist_id}
 * \param[in] crt_intmd Flag specifying whether to create intermediate
 *                      groups upon the creation of an object
 *
 * \return \herr_t
 *
 * \details H5Pset_create_intermediate_group()
 *
 * \since
 *
 */
H5_DLL herr_t H5Pset_create_intermediate_group(hid_t plist_id, unsigned crt_intmd);

/* Group creation property list (GCPL) routines */
H5_DLL herr_t H5Pget_est_link_info(hid_t plist_id, unsigned *est_num_entries /* out */, unsigned *est_name_len /* out */);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup GCPL
 *
 * \brief Queries whether link creation order is tracked and/or indexed in
 *        a group
 *
 * \param[in]  plist_id         Group or file creation property list
 *                              identifier
 * \param[out] crt_order_flags  Creation order flag(s)
 *
 * \return \herr_t
 *
 * \details H5Pget_link_creation_order() queries the group or file creation
 *          property list, \p plist_id, and returns a flag indicating whether
 *          link creation order is tracked and/or indexed in a group.
 *
 *          See H5Pset_link_creation_order() for a list of valid creation
 *          order flags, as passed in \p crt_order_flags, and their
 *          meanings.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_link_creation_order(hid_t plist_id, unsigned *crt_order_flags /* out */);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup GCPL
 *
 * \brief Queries the settings for conversion between compact and dense
 *        groups
 *
 * \gcpl_id{plist_id}
 * \param[out] max_compact Maximum number of links for compact storage
 * \param[out] min_dense   Minimum number of links for dense storage
 *
 * \return \herr_t
 *
 * \details H5Pget_link_phase_change() queries the maximum number of
 *          entries for a compact group and the minimum number of links
 *          to require before converting a group to a dense form.
 *
 *          In the compact format, links are stored as messages in the
 *          group’s header. In the dense format, links are stored in a
 *          fractal heap and indexed with a version 2 B-tree.
 *
 *          \p max_compact is the maximum number of links to store as
 *          header messages in the group header before converting the
 *          group to the dense format. Groups that are in the compact
 *          format and exceed this number of links are automatically
 *          converted to the dense format.
 *
 *          \p min_dense is the minimum number of links to store in the
 *          dense format. Groups which are in dense format and in which
 *          the number of links falls below this number are automatically
 *          converted back to the compact format.
 *
 *          In the compact format, links are stored as messages in the
 *          group’s header. In the dense format, links are stored in a
 *          fractal heap and indexed with a version 2 B-tree.
 *
 *          See H5Pset_link_phase_change() for a discussion of
 *          traditional, compact, and dense group storage.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_link_phase_change(hid_t plist_id, unsigned *max_compact /*out*/, unsigned *min_dense /*out*/);
H5_DLL herr_t H5Pget_local_heap_size_hint(hid_t plist_id, size_t *size_hint /*out*/);
H5_DLL herr_t H5Pset_est_link_info(hid_t plist_id, unsigned est_num_entries, unsigned est_name_len);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup GCPL
 *
 * \brief Sets creation order tracking and indexing for links in a group
 *
 * \param[in]  plist_id        Group or file creation property list
 *                             identifier
 * \param[out] crt_order_flags Creation order flag(s)
 *
 * \return \herr_t
 *
 * \details H5Pset_link_creation_order() sets flags for tracking and
 *          indexing links on creation order in groups created with the
 *          group (or file) creation property list \p plist_id.
 *
 *          \p crt_order_flags contains flags with the following meanings:
 *
 *          <table>
 *           <tr>
 *            <td>#H5P_CRT_ORDER_TRACKED</td>
 *            <td>Link creation order is tracked but not necessarily
 *                indexed</td>
 *           </tr>
 *           <tr>
 *            <td>#H5P_CRT_ORDER_INDEXED</td>
 *            <td>Link creation order is indexed (requires
 *                #H5P_CRT_ORDER_TRACKED)</td>
 *           </tr>
 *          </table>
 *
 *          The default behavior is that links are tracked and indexed by
 *          name, and link creation order is neither tracked nor indexed.
 *          The name is always the primary index for links in a group.
 *
 *          H5Pset_link_creation_order() can be used to set link creation
 *          order tracking, or to set link creation order tracking and
 *          indexing.
 *
 *          If (#H5P_CRT_ORDER_TRACKED | #H5P_CRT_ORDER_INDEXED) is
 *          specified for \p crt_order_flags, then links will be tracked
 *          and indexed by creation order. The creation order is added as
 *          a secondary index and enables faster queries and iterations
 *          by creation order.
 *
 *          If just #H5P_CRT_ORDER_TRACKED is specified for
 *          \p crt_order_flags, then links will be tracked by creation
 *          order, but not indexed by creation order. Queries and iterations
 *          by creation order will work but will be much slower for large
 *          groups than if #H5P_CRT_ORDER_INDEXED had been included.
 *
 * \note If a creation order index is to be built, it must be specified in
 *       the group creation property list. HDF5 currently provides no
 *       mechanism to turn on link creation order tracking at group
 *       creation time and to build the index later.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_link_creation_order(hid_t plist_id, unsigned crt_order_flags);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup GCPL
 *
 * \brief Sets the parameters for conversion between compact and dense
 *        groups
 *
 * \gcpl_id{plist_id}
 * \param[in] max_compact Maximum number of links for compact storage
 *                        (\a Default: 8)
 * \param[in] min_dense   Minimum number of links for dense storage
 *                        (\a Default: 6)
 *
 * \return \herr_t
 *
 * \details H5Pset_link_phase_change() sets the maximum number of entries
 *          for a compact group and the minimum number of links to allow
 *          before converting a dense group back to the compact format.
 *
 *          \p max_compact is the maximum number of links to store as
 *          header messages in the group header before converting the
 *          group to the dense format. Groups that are in compact format
 *          and which exceed this number of links are automatically
 *          converted to dense format.
 *
 *          \p min_dense is the minimum number of links to store in the
 *          dense format. Groups which are in dense format and in which
 *          the number of links falls below this threshold are
 *          automatically converted to compact format.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_link_phase_change(hid_t plist_id, unsigned max_compact, unsigned min_dense);
H5_DLL herr_t H5Pset_local_heap_size_hint(hid_t plist_id, size_t size_hint);

/* Map access property list (MAPL) routines */
#ifdef H5_HAVE_MAP_API
H5_DLL herr_t H5Pget_map_iterate_hints(hid_t mapl_id, size_t *key_prefetch_size /*out*/, size_t *key_alloc_size /*out*/);
H5_DLL herr_t H5Pset_map_iterate_hints(hid_t mapl_id, size_t key_prefetch_size, size_t key_alloc_size);CC_RDWR - Files opened through external links will be opened with write access

H5F_ACC_RDONLY - Files opened through external links will be opened with read-only access


#endif /*  H5_HAVE_MAP_API */

/* Link access property list (LAPL) routines */
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup LAPL
 *
 * \brief Retrieves the external link traversal file access flag from the
 *        specified link access property list
 *
 * \lapl_id
 * \param[out] flags File access flag for link traversal
 *
 * \return \herr_t
 *
 * \details H5Pget_elink_acc_flags() retrieves the file access flag used
 *          to open an external link target file from the specified link
 *          access property list.
 *
 *          Valid values for \p flags include:
 *          \li #H5F_ACC_RDWR - Files opened through external links will
 *                             be opened with write access
 *          \li #H5F_ACC_RDONLY - Files opened through external links will
 *                               be opened with read-only access
 *          \li #H5F_ACC_DEFAULT - Files opened through external links will
 *                                be opened with the same access flag as
 *                                the parent file
 *
 *          The value returned, if it is not #H5F_ACC_DEFAULT, will
 *          override the default access flag, which is the access flag
 *          used to open the parent file.
 *
 * \note <b>Example Usage:</b>
 *       The following code retrieves the external link access flag
 *       settings on the link access property list \p lapl_id into a
 *       local variable:
 *       <pre>
 *         unsigned acc_flags;
 *         status = H5Pget_elink_acc_flags(lapl_id, &acc_flags);
 *       </pre>
 *
 * \since 1.8.3
 *
 */
H5_DLL herr_t H5Pget_elink_acc_flags(hid_t lapl_id, unsigned *flags);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup LAPL
 *
 * \brief Retrieves the external link traversal callback function from the
 *        specified link access property list
 *
 * \lapl_id
 * \param[out] func    User-defined external link traversal callback
 *                     function
 * \param[out] op_data User-defined input data for the callback function
 *
 * \return \herr_t
 *
 * \details H5Pget_elink_cb() retrieves the user-defined external link
 *          traversal callback function defined in the specified link
 *          access property list.
 *
 *          The callback function may adjust the file access property
 *          list and file access flag to use when opening a file through
 *          an external link. The callback will be executed by the HDF5
 *          library immediately before opening the target file.
 *
 * \note <b>Failure Modes:</b> H5Pget_elink_cb() will fail if the link
 *       access property list identifier, lapl_id, is invalid.
 *
 * \note An invalid function pointer or data pointer, \p func or
 *       \p op_data respectively, may cause a segmentation fault or an
 *       invalid memory access.
 *
 * \note <b>Example Usage:</b> The following code retrieves the external
 *       link callback settings on the link access property list
 *       \p lapl_id into local variables:
 *       <pre>
 *       H5L_elink_traverse_t elink_callback_func;
 *       void *elink_callback_udata;
 *       status = H5Pget_elink_cb (lapl_id, &elink_callback_func,
 *                                 &elink_callback_udata);
 *       </pre>
 *
 * \since 1.8.3
 *
 */
H5_DLL herr_t H5Pget_elink_cb(hid_t lapl_id, H5L_elink_traverse_t *func, void **op_data);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup LAPL
 *
 * \brief Retrieves the file access property list identifier associated
 *        with the link access property list
 *
 * \lapl_id
 *
 * \return \hid_t{file access property list}
 *
 * \details H5Pget_elink_fapl() retrieves the file access property list
 *          identifier that is set for the link access property list
 *          identifier, \p lapl_id. The library uses this file access
 *          property list identifier to open the target file for the
 *          external link access. When no such identifier is set, this
 *          routine returns #H5P_DEFAULT.
 *
 * \see H5Pset_elink_fapl() and H5Lcreate_external().
 *
 * \since 1.8.0
 *
 */
H5_DLL hid_t H5Pget_elink_fapl(hid_t lapl_id);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup LAPL
 *
 * \brief Retrieves prefix applied to external link paths
 *
 * \lapl_id{plist_id}
 * \param[out] prefix Prefix applied to external link paths
 * \param[in]  size   Size of prefix, including null terminator
 *
 * \return If successful, returns a non-negative value specifying the size
 *         in bytes of the prefix without the NULL terminator; otherwise
 *         returns a negative value.
 *
 * \details H5Pget_elink_prefix() retrieves the prefix applied to the
 *          path of any external links traversed.
 *
 *          When an external link is traversed, the prefix is retrieved
 *          from the link access property list \p plist_id, returned in
 *          the user-allocated buffer pointed to by \p prefix, and
 *          prepended to the filename stored in the external link.
 *
 *          The size in bytes of the prefix, including the NULL terminator,
 *          is specified in \p size. If size is unknown, a preliminary
 *          H5Pget_elink_prefix() call with the pointer \p prefix set to
 *          NULL will return the size of the prefix without the NULL
 *          terminator.
 *
 * \since 1.8.0
 *
 */
H5_DLL ssize_t H5Pget_elink_prefix(hid_t plist_id, char *prefix, size_t size);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup LAPL
 *
 * \brief Retrieves the maximum number of link traversals
 *
 * \lapl_id{plist_id}
 * \param[out] nlinks Maximum number of links to traverse
 *
 * \return \herr_t
 *
 * \details H5Pget_nlinks() retrieves the maximum number of soft or
 *          user-defined link traversals allowed, \p nlinks, before the
 *          library assumes it has found a cycle and aborts the traversal.
 *          This value is retrieved from the link access property list
 *          \p plist_id.
 *
 *          The limit on the number of soft or user-defined link traversals
 *          is designed to terminate link traversal if one or more links
 *          form a cycle. User control is provided because some files may
 *          have legitimate paths formed of large numbers of soft or
 *          user-defined links. This property can be used to allow
 *          traversal of as many links as desired.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_nlinks(hid_t plist_id, size_t *nlinks);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup LAPL
 *
 * \brief Sets the external link traversal file access flag in a link
 *        access property list
 *
 * \lapl_id
 * \param[in] flags The access flag for external link traversal
 *
 * \return \herr_t
 *
 * \details H5Pset_elink_acc_flags() specifies the file access flag to use
 *          to open the target file of an external link. This allows
 *          read-only access of files reached through an external link in
 *          a file opened with write access, or vice-versa.
 *
 *          The library will normally use the file access flag used to
 *          open the parent file as the file access flag for the target
 *          file. This function provides a way to override that behavior.
 *
 *          Valid values for \p flags include:
 *          \li #H5F_ACC_RDWR - Causes files opened through external links
 *               to be opened with write access
 *          \li #H5F_ACC_RDONLY - Causes files opened through external
 *              links to be opened with read-only access
 *          \li #H5F_ACC_DEFAULT - Removes any external link file access
 *              flag setting from \p lapl_id, causing the file access flag
 *              setting to be taken from the parent file
 *
 *          The external link traversal callback function set by
 *          H5Pset_elink_cb() can override the setting from
 *          H5Pset_elink_acc_flags().
 *
 * \note <b>Motivation:</b> H5Pset_elink_acc_flags() is used to adjust the
 *       file access flag used to open files reached through external links.
 *       This may be useful to, for example, prevent modifying files
 *       accessed through an external link. Otherwise, the target file is
 *       opened with whatever flag was used to open the parent.
 *
 * \note <b>Example Usage:</b> The following code sets the link access
 *       property list \p lapl_id to open external link target files with
 *       read-only access:
 *        <pre>
 *         status = H5Pset_elink_acc_flags(lapl_id, H5F_ACC_RDONLY);
 *        </pre>
 *
 * \since 1.8.3
 *
 */
H5_DLL herr_t H5Pset_elink_acc_flags(hid_t lapl_id, unsigned flags);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup LAPL
 *
 * \brief Sets the external link traversal callback function in a link
 *        access property list
 *
 * \lapl_id
 * \param[in] func    User-defined external link traversal callback
 *                    function
 * \param[in] op_data User-defined input data for the callback function
 *
 * \return \herr_t
 *
 * \details H5Pset_elink_cb() sets a user-defined external link traversal
 *          callback function in the link access property list \p lapl_id.
 *          The callback function \p func must conform to the prototype
 *          specified in #H5L_elink_traverse_t.
 *
 *          The callback function may adjust the file access property
 *          list and file access flags to use when opening a file through
 *          an external link. The callback will be executed by the HDF5
 *          library immediately before opening the target file.
 *
 *          The callback will be made after the file access property list
 *          set by H5Pset_elink_fapl() and the file access flag set by
 *          H5Pset_elink_acc_flags() are applied, so changes made by this
 *          callback function will take precedence.
 *
 * \attention A file close degree property setting (H5Pset_fclose_degree())
 *            in this callback function or an associated property list will
 *            be ignored. A file opened by means of traversing an external
 *            link is always opened with the weak file close degree
 *            property setting, #H5F_CLOSE_WEAK.
 *
 * \note <b>Motivation:</b> H5Pset_elink_cb() is used to specify a
 *       callback function that is executed by the HDF5 library when
 *       traversing an external link. This provides a mechanism to set
 *       specific access permissions, modify the file access property
 *       list, modify the parent or target file, or take any other
 *       user-defined action. This callback function is used in
 *       situations where the HDF5 library's default behavior is not
 *       suitable.
 *
 * \note <b>Failure Modes:</b> H5Pset_elink_cb() will fail if the link
 *       access property list identifier, \p lapl_id, is invalid or if
 *       the function pointer, func, is NULL.
 *
 * \note An invalid function pointer, \p func, will cause a segmentation
 *       fault or other failure when an attempt is subsequently made to
 *       traverse an external link.
 *
 * \note <b>Examples Usage:</b>
 *       This example defines a callback function that prints the name
 *       of the target file every time an external link is followed, and
 *       sets this callback function on \p lapl_id.
 *       <pre>
 *          herr_t elink_callback(const char *parent_file_name, const char
 *                 *parent_group_name, const char *child_file_name, const char
 *                 *child_object_name, unsigned *acc_flags, hid_t fapl_id, void *op_data) {
 *              puts(child_file_name);
 *              return 0;
 *          }
 *          int main(void) {
 *              hid_t lapl_id = H5Pcreate(H5P_LINK_ACCESS);
 *              H5Pset_elink_cb(lapl_id, elink_callback, NULL);
 *                ...
 *          }
 *          </pre>
 *
 *
 * \todo Add Programming Note for C++ Developers Using C Functions
 *
 *
 * \since 1.8.3
 *
 */
H5_DLL herr_t H5Pset_elink_cb(hid_t lapl_id, H5L_elink_traverse_t func, void *op_data);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup LAPL
 *
 * \brief Sets a file access property list for use in accessing a file
 *        pointed to by an external link
 *
 * \lapl_id
 * \fapl_id
 *
 * \return \herr_t
 *
 * \details H5Pset_elink_fapl() sets the file access property list,
 *          \p fapl_id, to be used when accessing the target file of an
 *          external link associated with \p lapl_id.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_elink_fapl(hid_t lapl_id, hid_t fapl_id);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup LAPL
 *
 * \brief Sets prefix to be applied to external link paths
 *
 * \lapl_id{plist_id}
 * \param[in] prefix Prefix to be applied to external link paths
 *
 * \return \herr_t
 *
 * \details H5Pset_elink_prefix() sets the prefix to be applied to the
 *          path of any external links traversed. The prefix is prepended
 *          to the filename stored in the external link.
 *
 *          The prefix is specified in the user-allocated buffer \p prefix
 *          and set in the link access property list \p plist_id. The buffer
 *          should not be freed until the property list has been closed.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_elink_prefix(hid_t plist_id, const char *prefix);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup LAPL
 *
 * \brief Sets maximum number of soft or user-defined link traversals
 *
 * \lapl_id{plist_id}
 * \param[in] nlinks Maximum number of links to traverse
 *
 * \return \herr_t
 *
 * \details H5Pset_nlinks() sets the maximum number of soft or user-defined
 *          link traversals allowed, \p nlinks, before the library assumes
 *          it has found a cycle and aborts the traversal. This value is
 *          set in the link access property list \p plist_id.
 *
 *          The limit on the number of soft or user-defined link traversals
 *          is designed to terminate link traversal if one or more links
 *          form a cycle. User control is provided because some files may
 *          have legitimate paths formed of large numbers of soft or
 *          user-defined links. This property can be used to allow
 *          traversal of as many links as desired.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_nlinks(hid_t plist_id, size_t nlinks);

/* Object copy property list (OCPYPL) routines */

/**
 *-------------------------------------------------------------------------
 *
 * \ingroup OCPPL
 *
 * \brief Adds a path to the list of paths that will be searched in the
 *        destination file for a matching committed datatype
 *
 * \param[in] plist_id Object copy property list identifier
 * \param[in] path     The path to be added
 *
 * \return \herr_t
 *
 * \details H5Padd_merge_committed_dtype_path() adds a path, \p path,
 *          which points to a committed datatype, to the current list of
 *          suggested paths stored in the object copy property list
 *          \p plist_id. The search as described in the next paragraph is
 *          effective only if the #H5O_COPY_MERGE_COMMITTED_DTYPE_FLAG is
 *          enabled in the object copy property list via
 *          H5Pset_copy_object().
 *
 *          When copying a committed datatype, a dataset with a committed
 *          datatype, or an object with an attribute of a committed
 *          datatype, the default behavior of H5Ocopy() is to search for
 *          a matching committed datatype:
 *          <ol>
 *          <li> First search the list of suggested paths in the object
 *               copy property list.</li>
 *          <li> Then, if no match has been found, search all the committed
 *               datatypes in the destination file.
 *          </ol>
 *          The default Step 2 in this search process can be changed by
 *          setting a callback function (see H5Pset_mcdt_search_cb()).
 *
 *          Two datatypes are determined equal if their descriptions are
 *          identical, in a manner similar to H5Tequal(). If either
 *          committed datatype has one or more attributes, then all
 *          attributes must be present in both committed datatypes and they
 *          must be identical. Two attributes are considered identical if
 *          their datatype description, dataspace, and raw data values are
 *          the same. However, if an attribute uses a committed datatype,
 *          that committed datatype’s attributes will not be compared.
 *
 *          If a match is found, H5Ocopy() will perform the following in
 *          the destination file:
 *          \li For a committed datatype, the library will create a hard
 *              link to the found datatype.
 *          \li For a dataset that uses a committed datatype, the library
 *              will modify the copied dataset to use the found committed
 *              datatype as its datatype.
 *          \li For an object with an attribute of a committed datatype,
 *              the library will modify the copied object’s attribute to
 *              use the found committed datatype as its datatype.
 *
 *          If no match is found, H5Ocopy() will perform the following in
 *          the destination file:
 *          \li For a committed datatype, the library will copy it as it
 *              would any other object, creating a named committed
 *              datatype at the destination. That is, the library will
 *              create a committed datatype that is accessible in the
 *              file by a unique path.
 *          \li For a dataset that uses a committed datatype, the
 *              library will copy the datatype as an anonymous
 *              committed datatype and use that as the dataset’s
 *              datatype.
 *          \li For an object with an attribute of a committed datatype,
 *              the library will copy the datatype as an anonymous
 *              committed datatype and use that as the attribute’s
 *              datatype.
 *
 * \attention H5Padd_merge_committed_dtype_path() will fail if the object
 *            copy property list is invalid.
 *            It will also fail if there is insufficient memory when
 *            duplicating \p path.
 *
 * \note \b Motivation: H5Padd_merge_committed_dtype_path() provides a
 *       means to override the default behavior of H5Ocopy() when
 *       #H5O_COPY_MERGE_COMMITTED_DTYPE_FLAG is set in an object
 *       copy property list.
 *       H5Padd_merge_committed_dtype_path() is the mechanism for
 *       suggesting search paths where H5Ocopy() will look for a
 *       matching committed datatype. This can be substantially
 *       faster than the default approach of searching the entire
 *       destination file for a match.
 *
 * \see
 *    \li H5Ocopy()
 *    \li #H5O_mcdt_search_cb_t
 *    \li H5Padd_merge_committed_dtype_path()
 *    \li H5Pfree_merge_committed_dtype_paths()
 *    \li H5Pget_mcdt_search_cb()
 *    \li H5Pset_copy_object()
 *    \li H5Pset_mcdt_search_cb()
 *
 * \todo Removed Example Usage.
 * \todo missing link to "Copying Committed Datatypes with H5Ocopy - A
 *       comprehensive discussion of copying committed datatypes (PDF)
 *       in Advanced Topics in HDF5
 *
 * \since 1.8.9
 *
 */
H5_DLL herr_t H5Padd_merge_committed_dtype_path(hid_t plist_id, const char *path);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup OCPPL
 *
 * \brief Clears the list of paths stored in the object copy property list
 *
 * \param[in] plist_id Object copy property list identifier
 *
 * \return \herr_t
 *
 * \details H5Pfree_merge_committed_dtype_paths() clears the suggested
 *          paths stored in the object copy property list \p plist_id.
 *          These are the suggested paths previously set with
 *          H5Padd_merge_committed_dtype_path().
 *
 * \attention H5Pfree_merge_committed_dtype_paths() will fail if the
 *            object copy property list is invalid.
 *
 * \todo Removed Example Usage.
 *
 * \see
 *    \li H5Ocopy()
 *    \li #H5O_mcdt_search_cb_t
 *    \li H5Padd_merge_committed_dtype_path()
 *    \li H5Pfree_merge_committed_dtype_paths()
 *    \li H5Pget_mcdt_search_cb()
 *    \li H5Pset_copy_object()
 *    \li H5Pset_mcdt_search_cb()
 *
 * \since 1.8.9
 *
 */
H5_DLL herr_t H5Pfree_merge_committed_dtype_paths(hid_t plist_id);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup OCPPL
 *
 * \brief Retrieves the properties to be used when an object is copied
 *
 * \param[in]  plist_id     Object copy property list identifier
 * \param[out] copy_options Copy option(s) set in the object copy property
 *                          list
 *
 * \return \herr_t
 *
 * \details H5Pget_copy_object() retrieves the properties currently
 *          specified in the object copy property list \p plist_id, which
 *          will be invoked when a new copy is made of an existing object.
 *
 *          \p copy_options is a bit map indicating the flags, or
 *          properties, governing object copying that are set in the
 *          property list \p plist_id.
 *
 *          The available flags are described in H5Pset_copy_object().
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_copy_object(hid_t plist_id, unsigned *copy_options /*out*/);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup OCPPL
 *
 * \brief Retrieves the callback function from the specified object copy
 *        property list
 *
 * \param[in]  plist_id     Object copy property list identifier
 * \param[out] func         User-defined callback function
 * \param[out] op_data      User-defined data for the callback
 *                          function
 *
 * \return \herr_t
 *
 * \details H5Pget_mcdt_search_cb() retrieves the user-defined callback
 *          function and the user data that are set via
 *          H5Pset_mcdt_search_cb() in the object copy property list
 *          \p plist_id.
 *
 *          The callback function will be returned in the parameter \p func
 *          and the user data will be returned in the parameter \p op_data.
 *
 * \attention H5Pget_mcdt_search_cb() will fail if the object copy property
 *            list is invalid.
 *
 * \see
 *    \li H5Ocopy()
 *    \li #H5O_mcdt_search_cb_t
 *    \li H5Padd_merge_committed_dtype_path()
 *    \li H5Pfree_merge_committed_dtype_paths()
 *    \li H5Pget_mcdt_search_cb()
 *    \li H5Pset_copy_object()
 *    \li H5Pset_mcdt_search_cb()
 *
 * \todo Link to Copying Committed Datatypes with H5Ocopy was removed.
 *
 * \since 1.8.9
 *
 */
H5_DLL herr_t H5Pget_mcdt_search_cb(hid_t plist_id, H5O_mcdt_search_cb_t *func, void **op_data);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup OCPPL
 *
 * \brief Sets properties to be used when an object is copied
 *
 * \param[in]  plist_id     Object copy property list identifier
 * \param[out] copy_options Copy option(s) to be set
 *
 * \return \herr_t
 *
 * \details H5Pset_copy_object() sets properties in the object copy
 *          property list \p plist_id. When an existing object is copied,
 *          that property list will determine how the new copy is created.
 *
 *          The following flags are available for use in an object copy
 *          property list:
 *
 *          <table>
 *           <tr>
 *            <td>#H5O_COPY_SHALLOW_HIERARCHY_FLAG</td>
 *            <td>Copy only immediate members of a group<br />
 *                <em>Default behavior, without flag:</em> Recursively
 *                copy all objects in and below the group.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5O_COPY_EXPAND_SOFT_LINK_FLAG</td>
 *            <td>Expand soft links into new objects<br />
 *                <em>Default behavior, without flag:</em> Copy soft
 *                links as they are.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5O_COPY_EXPAND_EXT_LINK_FLAG</td>
 *            <td>Expand external link into new objects<br />
 *                <em>Default behavior, without flag:</em> Copy external
 *                    links as they are.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5O_COPY_EXPAND_REFERENCE_FLAG</td>
 *            <td>Copy objects that are pointed to by references and
 *                update reference values in destination file<br />
 *                <em>Default behavior, without flag:</em> Set reference
 *                    values in destination file to zero (0)</td>
 *           </tr>
 *           <tr>
 *            <td>#H5O_COPY_WITHOUT_ATTR_FLAG</td>
 *            <td>Copy object without copying attributes<br />
 *                <em>Default behavior, without flag:</em> Copy object
 *                    with all its attributes</td>
 *           </tr>
 *           <tr>
 *            <td>#H5O_COPY_MERGE_COMMITTED_DTYPE_FLAG</td>
 *            <td>Use a matching committed datatype in the destination
 *                file when copying a committed datatype, a dataset with
 *                a committed datatype, or an object with an attribute
 *                of committed datatype <br />
 *                <em>Default behavior without flag:</em>
 *
 *                \li A committed datatype in the source will be copied to
 *                    the destination as a committed datatype.
 *                \li If a dataset in the source uses a committed
 *                    datatype or an object in the source has an attribute
 *                    of a committed datatype, that committed datatype will
 *                    be written to the destination as an anonymous
 *                    committed datatype.
 *                    If copied in a single H5Ocopy() operation, objects
 *                    that share a committed datatype in the source will
 *                    share an anonymous committed dataype in the
 *                    destination copy. Subsequent H5Ocopy() operations,
 *                    however, will be unaware of prior anonymous committed
 *                    dataypes and will create new ones.
 *
 *                    See the “See Also” section immediately below for
 *                    functions related to the use of this flag.</td>
 *           </tr>
 *          </table>
 *
 * \see
 *    Functions and a callback function used to tune committed datatype
 *    copying behavior:
 *    \li #H5O_mcdt_search_cb_t
 *    \li H5Padd_merge_committed_dtype_path()
 *    \li H5Pfree_merge_committed_dtype_paths()
 *    \li H5Pget_mcdt_search_cb()
 *    \li H5Pset_copy_object()
 *    \li H5Pset_mcdt_search_cb()
 *
 * \todo Link to Copying Committed Datatypes with H5Ocopy was removed.
 * \version 1.8.9 #H5O_COPY_MERGE_COMMITTED_DTYPE_FLAG added in this release.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_copy_object(hid_t plist_id, unsigned copy_options);
/**
 *-------------------------------------------------------------------------
 *
 * \ingroup OCPPL
 *
 * \brief Sets the callback function that H5Ocopy() will invoke before
 *        searching the entire destination file for a matching committed
 *        datatype
 *
 * \param[in] plist_id Object copy property list identifier
 * \param[in] func     User-defined callback function
 * \param[in] op_data  User-defined input data for the callback function
 *
 * \return \herr_t
 *
 * \details H5Pset_mcdt_search_cb() allows an application to set a
 *          callback function, \p func, that will be invoked before
 *          searching the destination file for a matching committed
 *          datatype. The default, global search process is described in
 *          H5Padd_merge_committed_dtype_path().
 *
 *          The callback function must conform to the #H5O_mcdt_search_cb_t
 *          prototype and will return an instruction for one of the
 *          following actions:
 *
 *          \li Continue the search for a matching committed datatype in
 *              the destination file.
 *          \li Discontinue the search for a matching committed datatype.
 *              H5Ocopy() will then apply the default behavior of creating
 *              an anonymous committed datatype.
 *          \li Abort the copy operation and exit H5Ocopy().
 *
 * \attention H5Pset_mcdt_search_cb() will fail if the
 *            object copy property list is invalid.
 *
 * \warning If the callback function return value causes H5Ocopy() to
 *          abort, the destination file may be left in an inconsistent or
 *          corrupted state.
 *
 * \note \b Motivation: H5Pset_mcdt_search_cb() provides the means to
 *       define a callback function. An application can then use that
 *       callback to take an additional action before the default search
 *       of all committed datatypes in the destination file or to take an
 *       action that replaces the default search. This mechanism is
 *       intended to improve performance when the global search might
 *       take a long time.
 *
 * \todo Removed Example Usage.
 * \see
 *    \li H5Ocopy()
 *    \li #H5O_mcdt_search_cb_t
 *    \li H5Padd_merge_committed_dtype_path()
 *    \li H5Pfree_merge_committed_dtype_paths()
 *    \li H5Pget_mcdt_search_cb()
 *    \li H5Pset_copy_object()
 *    \li H5Pset_mcdt_search_cb()
 *
 * \todo Link removed to "Copying Committed Datatypes with H5Ocopy" in Advanced Topics in HDF5
 * \todo Programming Note for C++ Developers Using C Functions:
 *
 * \since 1.8.9
 *
 */
H5_DLL herr_t H5Pset_mcdt_search_cb(hid_t plist_id, H5O_mcdt_search_cb_t func, void *op_data);

/* Symbols defined for compatibility with previous versions of the HDF5 API.
 *
 * Use of these symbols is deprecated.
 */
#ifndef H5_NO_DEPRECATED_SYMBOLS

/* Macros */

/* We renamed the "root" of the property list class hierarchy */
#define H5P_NO_CLASS            H5P_ROOT


/* Typedefs */


/* Function prototypes */
H5_DLL herr_t H5Pregister1(hid_t cls_id, const char *name, size_t size,
    void *def_value, H5P_prp_create_func_t prp_create,
    H5P_prp_set_func_t prp_set, H5P_prp_get_func_t prp_get,
    H5P_prp_delete_func_t prp_del, H5P_prp_copy_func_t prp_copy,
    H5P_prp_close_func_t prp_close);
H5_DLL herr_t H5Pinsert1(hid_t plist_id, const char *name, size_t size,
    void *value, H5P_prp_set_func_t prp_set, H5P_prp_get_func_t prp_get,
    H5P_prp_delete_func_t prp_delete, H5P_prp_copy_func_t prp_copy,
    H5P_prp_close_func_t prp_close);
H5_DLL herr_t H5Pencode1(hid_t plist_id, void *buf, size_t *nalloc);
/**
 *-------------------------------------------------------------------------
 * \ingroup OCPL
 *
 * \brief Returns information about a filter in a pipeline (DEPRECATED)
 *
 * \todo H5Pget_filter1() prototype does not match source in H5Pocpl.c.
 *       Also, it is not in a deprecated file. Is that okay?
 *
 * \plist_id{plist_id}
 * \param[in] idx Sequence number within the filter pipeline of the filter
 *                for which information is sought
 * \param[out] flags Bit vector specifying certain general properties of
 *                the filter
 * \param[in,out] cd_nelmts Number of elements in \p cd_values
 * \param[out] cd_values Auxiliary data for the filter
 * \param[in] namelen Anticipated number of characters in \p name
 * \param[out] name Name of the filter
 *
 * \return Returns the filter identifier if successful;  Otherwise returns
 *         a negative value. See: #H5Z_filter_t
 *
 * \details H5Pget_filter1() returns information about a filter, specified
 *          by its filter number, in a filter pipeline, specified by the
 *          property list with which it is associated.
 *
 *          \p plist_id must be a dataset or group creation property list.
 *
 *          \p idx is a value between zero and N-1, as described in
 *          H5Pget_nfilters(). The function will return a negative value
 *          if the filter number is out of range.
 *
 *          The structure of the \p flags argument is discussed in
 *          H5Pset_filter().
 *
 *          On input, \p cd_nelmts indicates the number of entries in the
 *          \p cd_values array, as allocated by the caller; on return,
 *          \p cd_nelmts contains the number of values defined by the filter.
 *
 *          If \p name is a pointer to an array of at least \p namelen
 *          bytes, the filter name will be copied into that array. The name
 *          will be null terminated if \p namelen is large enough. The
 *          filter name returned will be the name appearing in the file, the
 *          name registered for the filter, or an empty string.
 *
 * \version 1.8.5 Function extended to work with group creation property
 *                lists.
 * \version 1.8.0 N-bit and scale-offset filters added.
 * \version 1.8.0 Function H5Pget_filter() renamed to H5Pget_filter1() and
 *                deprecated in this release.
 * \version 1.6.4 \p filter parameter type changed to unsigned.
 *
 */
H5_DLL H5Z_filter_t H5Pget_filter1(hid_t plist_id, unsigned idx,
    unsigned int *flags/*out*/, size_t *cd_nelmts/*out*/,
    unsigned cd_values[]/*out*/, size_t namelen, char name[]);
H5_DLL herr_t H5Pget_filter_by_id1(hid_t plist_id, H5Z_filter_t id,
    unsigned int *flags/*out*/, size_t *cd_nelmts/*out*/,
    unsigned cd_values[]/*out*/, size_t namelen, char name[]/*out*/);
H5_DLL herr_t H5Pget_version(hid_t plist_id, unsigned *boot/*out*/,
         unsigned *freelist/*out*/, unsigned *stab/*out*/,
         unsigned *shhdr/*out*/);
H5_DLL herr_t H5Pset_file_space(hid_t plist_id, H5F_file_space_type_t strategy, hsize_t threshold);
H5_DLL herr_t H5Pget_file_space(hid_t plist_id, H5F_file_space_type_t *strategy, hsize_t *threshold);
#endif /* H5_NO_DEPRECATED_SYMBOLS */

#ifdef __cplusplus
}
#endif
#endif /* _H5Ppublic_H */

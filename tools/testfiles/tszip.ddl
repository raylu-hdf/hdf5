#############################
Expected output for 'h5dump -H -p -d szip tfilters.h5'
#############################
HDF5 "tfilters.h5" {
DATASET "szip" {
   DATATYPE  H5T_STD_I32LE
   DATASPACE  SIMPLE { ( 20, 10 ) / ( 20, 10 ) }
   STORAGE_LAYOUT CHUNKED {
      SIZE 372 ( 10, 5 )
   }
   FILTERS {
      COMPRESSION SZIP {
         PIXELS_PER_BLOCK 4
         MODE K13
         CODING NEAREST NEIGHBOUR
         BYTE_ORDER LSB
         HEADER RAW
      }
   }
   FILLVALUE {
      FILL_TIME IFSET
      ALLOC_TIME INCR
      VALUE  -99   
   }
}
}

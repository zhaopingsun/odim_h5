/*------------------------------------------------------------------------------
 * Rainfields ODIM HDF5 Library (rainHDF)
 *
 * Copyright (C) 2011 Commonwealth of Australia, Bureau of Meteorology
 * See COPYING for licensing and warranty details
 *----------------------------------------------------------------------------*/
#ifndef RAINHDF_PRODUCT_H
#define RAINHDF_PRODUCT_H

#include "base.h"

namespace rainhdf
{
  /// Base class for a top level ODIM_H5 object file
  class product : public base
  {
  protected:
    // TODO - source is mandatory and should be in the constructor
    /// Create a new product
    product(const std::string& file, object_type type, time_t valid_time);
    /// Open an existing ODIM_H5 product
    product(const std::string& file, object_type type, bool read_only);

  public:
    /// Get the nominal (valid) time of the data/product
    time_t valid_time() const { return get_att<time_t>(hnd_what_, atn_date, atn_time); }
    /// Write the nominal (valid) time of the data/product
    void set_valid_time(time_t valid_time) { set_att(hnd_what_, atn_date, atn_time, valid_time); }

    /// Read the source attribute values
    void get_source(
          std::string& wmo
        , std::string& radar
        , std::string& orig_centre
        , std::string& place
        , std::string& country
        , std::string& comment) const;
    /// Write the data source attriubte
    void set_source(
          const std::string& wmo
        , const std::string& radar
        , const std::string& orig_centre
        , const std::string& place
        , const std::string& country
        , const std::string& comment);
  };
}

#endif



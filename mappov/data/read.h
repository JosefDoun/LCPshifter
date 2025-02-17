# ifndef __READ_DATA
# define __READ_DATA

# include <gdal/gdal_priv.h>
# include "../memory/memory.h"


struct _t_coords;
typedef _t_coords t_coords;


struct Dataset
{
	private:
	/* GDALDataset */
	GDALDatasetUniquePtr ds;
	Memory &memory;
	/* Tile dimensions. */
	int t_size_x;
	int t_size_y;
	/* Number of tiles in dataset. */
	int n_tiles;
	/* Function returning tile coordinates in pixels. */
	t_coords tile_coords(uint16_t) const;

	public:
	Dataset(std::string, Memory&);
	Dataset(std::string, uint16_t, uint16_t, Memory&);
	/* Fetch i-th tile of dataset. */
	float * operator[](uint16_t) const;
	/* Read a raster from file into a dataset. */
	static GDALDatasetUniquePtr ReadDataset(std::string /* File path. */ p);
	/* Friend functions. */
	friend void Transform(const Dataset*, const Dataset*,
						  const float, const float, Memory&);
};


# endif

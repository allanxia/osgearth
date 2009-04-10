/* -*-c++-*- */
/* osgEarth - Dynamic map generation toolkit for OpenSceneGraph
 * Copyright 2008-2009 Pelican Ventures, Inc.
 * http://osgearth.org
 *
 * osgEarth is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#ifndef OSGEARTH_WCS_PLUGIN_WCS11SOURCE_H_
#define OSGEARTH_WCS_PLUGIN_WCS11SOURCE_H_ 1

#include <osgEarth/MapConfig>
#include <osgEarth/TileKey>
#include <osgEarth/TileSource>
#include <osgEarth/HTTPClient>
#include <osg/Image>
#include <osg/Shape>
#include <osgDB/ReaderWriter>
#include <string>

using namespace osgEarth;

class WCS11Source : public TileSource
{
public:
    WCS11Source( const osgDB::ReaderWriter::Options* options );
    
    osg::Image* createImage( const TileKey* key );

    osg::HeightField* createHeightField( const TileKey* key );
    
    std::string getExtension() const;

public: // TileSource interface

    // override
    const Profile* createProfile( const Profile* mapProfile, const std::string& configPath );

private:
    std::string _url;
    std::string _identifier;
    std::string _cov_format;
    std::string _osg_format;
    std::string _srs;
    std::string _elevation_unit;
    int         _tile_size;

    HTTPRequest* createRequest( const TileKey* key ) const;
};

#endif // OSGEARTH_WCS_PLUGIN_WCS11SOURCE_H_
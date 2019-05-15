//
// BulkExtraction.h
//
// Library: SQL
// Package: SQLCore
// Module:  Bulk
//
// Definition of the BulkExtraction class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef SQL_Bulk_INCLUDED
#define SQL_Bulk_INCLUDED


#include "Poco/Void.h"
#include "Poco/SQL/Limit.h"


namespace Poco {
namespace SQL {


class Poco_SQL_API Bulk
{
public:
	Bulk(const Limit& limit);
		/// Creates the Bulk.

	Bulk(Poco::UInt32 value);
		/// Creates the Bulk.

	~Bulk();
		/// Destroys the bulk.

	const Limit& limit() const;
		/// Returns the limit associated with this bulk object.

	Poco::UInt32 size() const;
		/// Returns the value of the limit associated with
		/// this bulk object.

private:
	Bulk();

	Limit _limit;
};


///
/// inlines
///
inline const Limit& Bulk::limit() const
{
	return _limit;
}


inline Poco::UInt32 Bulk::size() const
{
	return _limit.value();
}


namespace Keywords {


inline Bulk bulk(const Limit& limit = Limit(static_cast<Limit::SizeT>(Limit::LIMIT_UNLIMITED), false, false))
	/// Convenience function for creation of bulk.
{
	return Bulk(limit);
}


inline void bulk(Void)
	/// Dummy bulk function. Used for bulk binding creation
	/// (see BulkBinding) and bulk extraction signalling to Statement.
{
}


} // namespace Keywords


typedef void (*BulkFnType)(Void);


} } // namespace Poco::SQL


#endif // Data_Bulk_INCLUDED

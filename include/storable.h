#ifndef STORABLE_H_
#define STORABLE_H_

#include "loadable.h"
#include "database.h"

class Storable : public Loadable {
	public:
		DatabaseRef getSink() const;
	protected:
		Storable(const DatabaseRef, const std::string& type);
		Storable(const Storable &);
		Storable(const UUID &id, const DatabaseRef source);

		void stashID(const std::string &,const UUID&);
		void stashString(const std::string &,const std::string&);
		void stashInt(const std::string &, const uint64_t &);

	private:
		std::string type;
		DatabaseRef sink;
};

#endif

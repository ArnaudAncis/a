file open_file( const std::string& filename,
                bool writeable = true,
                bool createIfMissing = true );

open_file(fn, false);
// is same as
open_file(fn, false, true);
// but I want
open_file(fn, true, false);

#ifndef UTIL_FILE_H_
#define UTIL_FILE_H_

#include <sys/types.h>
#include <sys/stat.h>

static
inline bool file_exists(const char *filename){
	return (GetFileAttributesA(filename) != INVALID_FILE_ATTRIBUTES);
}

static
inline bool is_dir(const char *filename){
	struct stat st;
	if(stat(filename, &st) == -1){
		return false;
	}
	return (bool)(st.st_mode & _S_IFDIR != 0);
}

static
inline bool is_file(const char *filename){
	struct stat st;
	if(stat(filename, &st) == -1){
		return false;
	}
	int mode = st.st_mode & _S_IFREG;
	return (mode > 0);
}

#endif

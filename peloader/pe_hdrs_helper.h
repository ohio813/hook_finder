#pragma once

#include <Windows.h>
#include "util.h"

bool is64bit(const BYTE *pe_buffer);

BYTE* get_nt_hrds(const BYTE *pe_buffer);
IMAGE_NT_HEADERS32* get_nt_hrds32(const BYTE *pe_buffer);
IMAGE_NT_HEADERS64* get_nt_hrds64(const BYTE *pe_buffer);

DWORD get_hdrs_size(const BYTE *pe_buffer);

IMAGE_DATA_DIRECTORY* get_pe_directory(const BYTE* pe_buffer, DWORD dir_id);

ULONGLONG get_image_base(const BYTE *pe_buffer);

//set a new image base in headers
bool update_image_base(BYTE* payload, ULONGLONG destImageBase);

size_t get_sections_count(const BYTE* buffer, const size_t buffer_size);
PIMAGE_SECTION_HEADER get_section_hdr(const BYTE* buffer, const size_t buffer_size, size_t section_num);

bool is_module_dll(BYTE* payload);

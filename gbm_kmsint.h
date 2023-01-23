/*
 * Copyright (c) 2013 Renesas Solutions Corp.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Authors:
 *    Takanari Hayama <taki@igel.co.jp>
 */

#ifndef __gbm_kmsint_h__
#define __gbm_kmsint_h__

#include <kms_dumb.h>
#include <stdbool.h>

#include "gbmint.h"

struct gbm_kms_device {
	struct gbm_device base;
	struct kms_driver *kms;
};

#define MAX_PLANES	3

struct gbm_kms_plane {
	uint32_t handle;
	uint32_t stride;
};

struct gbm_kms_bo {
	struct gbm_bo base;
	struct kms_bo *bo;
	void *addr;
	int map_ref;
	int fd;			// FD for export
	int locked;

	uint32_t size;
	bool allocated;
	bool allocated_handle;

	// for multi-planar support
	int num_planes;
	struct gbm_kms_plane planes[MAX_PLANES];
};

struct gbm_kms_surface {
	struct gbm_surface base;
	struct gbm_kms_bo *bo[2];
	int front;
	int (*set_bo)(struct gbm_kms_surface *, int, void *, int, uint32_t);
};

/* Internal API */
static inline struct gbm_kms_surface *gbm_kms_surface(struct gbm_surface *surface)
{
	return (struct gbm_kms_surface*)surface;
}

static inline void gbm_kms_set_front(struct gbm_kms_surface *surface, int front)
{
	surface->front = front;
}

static inline int gbm_kms_get_front(struct gbm_kms_surface *surface)
{
	return surface->front;
}

static inline int gbm_kms_is_bo_locked(struct gbm_kms_bo *bo)
{
	return bo->locked;
}

static inline int gbm_kms_set_bo(struct gbm_kms_surface *surface, int n, void *addr, int fd, uint32_t stride)
{
	return surface->set_bo(surface, n, addr, fd, stride);
}

#endif

/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2011 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU Lesser General Public License Version 2.1
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef __CD_INHIBIT_H
#define __CD_INHIBIT_H

#include <glib-object.h>

G_BEGIN_DECLS

#define CD_TYPE_INHIBIT		(cd_inhibit_get_type ())
#define CD_INHIBIT(o)		(G_TYPE_CHECK_INSTANCE_CAST ((o), CD_TYPE_INHIBIT, CdInhibit))
#define CD_INHIBIT_CLASS(k)	(G_TYPE_CHECK_CLASS_CAST((k), CD_TYPE_INHIBIT, CdInhibitClass))
#define CD_IS_INHIBIT(o)	(G_TYPE_CHECK_INSTANCE_TYPE ((o), CD_TYPE_INHIBIT))
#define CD_IS_INHIBIT_CLASS(k)	(G_TYPE_CHECK_CLASS_TYPE ((k), CD_TYPE_INHIBIT))
#define CD_INHIBIT_GET_CLASS(o)	(G_TYPE_INSTANCE_GET_CLASS ((o), CD_TYPE_INHIBIT, CdInhibitClass))

typedef struct _CdInhibitPrivate	CdInhibitPrivate;
typedef struct _CdInhibit		CdInhibit;
typedef struct _CdInhibitClass		CdInhibitClass;

struct _CdInhibit
{
	 GObject		 parent;
	 CdInhibitPrivate	*priv;
};

struct _CdInhibitClass
{
	GObjectClass		 parent_class;
};

GType		 cd_inhibit_get_type		(void);
CdInhibit	*cd_inhibit_new			(void);

gboolean	 cd_inhibit_add			(CdInhibit	*inhibit,
						 const gchar	*sender,
						 GError		**error);
gboolean	 cd_inhibit_remove		(CdInhibit	*inhibit,
						 const gchar	*sender,
						 GError		**error);
gboolean	 cd_inhibit_valid		(CdInhibit	*inhibit);

G_END_DECLS

#endif /* __CD_INHIBIT_H */

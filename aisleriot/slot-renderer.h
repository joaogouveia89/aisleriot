/*
 *  Copyright © 2008 Neil Roberts
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __AISLERIOT_SLOT_RENDERER_H__
#define __AISLERIOT_SLOT_RENDERER_H__

#include <clutter/clutter-actor.h>
#include <libgames-support/games-card-images.h>
#include "card-cache.h"
#include "game.h"

G_BEGIN_DECLS

#define AISLERIOT_TYPE_SLOT_RENDERER                                    \
  (aisleriot_slot_renderer_get_type())
#define AISLERIOT_SLOT_RENDERER(obj)                                    \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj),                                   \
                               AISLERIOT_TYPE_SLOT_RENDERER,            \
                               AisleriotSlotRenderer))
#define AISLERIOT_SLOT_RENDERER_CLASS(klass)                            \
  (G_TYPE_CHECK_CLASS_CAST ((klass),                                    \
                            AISLERIOT_TYPE_SLOT_RENDERER,               \
                            AisleriotSlotRendererClass))
#define AISLERIOT_IS_SLOT_RENDERER(obj)                                 \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj),                                   \
                               AISLERIOT_TYPE_SLOT_RENDERER))
#define AISLERIOT_IS_SLOT_RENDERER_CLASS(klass)                         \
  (G_TYPE_CHECK_CLASS_TYPE ((klass),                                    \
                            AISLERIOT_TYPE_SLOT_RENDERER))
#define AISLERIOT_SLOT_RENDERER_GET_CLASS(obj)                          \
  (G_TYPE_INSTANCE_GET_CLASS ((obj),                                    \
                              AISLERIOT_TYPE_SLOT_RENDERER,             \
                              AisleriotSlotRendererClass))

typedef struct _AisleriotSlotRenderer        AisleriotSlotRenderer;
typedef struct _AisleriotSlotRendererClass   AisleriotSlotRendererClass;
typedef struct _AisleriotSlotRendererPrivate AisleriotSlotRendererPrivate;

struct _AisleriotSlotRendererClass
{
  ClutterActorClass parent_class;
};

struct _AisleriotSlotRenderer
{
  ClutterActor parent;

  AisleriotSlotRendererPrivate *priv;
};

GType aisleriot_slot_renderer_get_type (void) G_GNUC_CONST;

ClutterActor *aisleriot_slot_renderer_new (AisleriotCardCache *cache,
                                           Slot *slot);

void aisleriot_slot_renderer_set_highlight (AisleriotSlotRenderer *srend,
                                            guint hightlight_start);
guint aisleriot_slot_renderer_get_highlight (AisleriotSlotRenderer *srend);

G_END_DECLS

#endif /* __AISLERIOT_SLOT_RENDERER_H__ */
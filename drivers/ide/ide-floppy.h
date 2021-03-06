/*
 * drivers/ide/ide-floppy.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef __IDE_FLOPPY_H
#define __IDE_FLOPPY_H

#include "ide-gd.h"

#ifdef CONFIG_IDE_GD_ATAPI
/*
 * Pages of the SELECT SENSE / MODE SENSE packet commands.
 * See SFF-8070i spec.
 */
#define	IDEFLOPPY_CAPABILITIES_PAGE	0x1b
#define IDEFLOPPY_FLEXIBLE_DISK_PAGE	0x05

/* IOCTLs used in low-level formatting. */
#define	IDEFLOPPY_IOCTL_FORMAT_SUPPORTED	0x4600
#define	IDEFLOPPY_IOCTL_FORMAT_GET_CAPACITY	0x4601
#define	IDEFLOPPY_IOCTL_FORMAT_START		0x4602
#define IDEFLOPPY_IOCTL_FORMAT_GET_PROGRESS	0x4603

/* ide-floppy.c */
extern const struct ide_disk_ops ide_atapi_disk_ops;
void ide_floppy_create_mode_sense_cmd(struct ide_atapi_pc *, u8);
void ide_floppy_create_read_capacity_cmd(struct ide_atapi_pc *);

/* ide-floppy_ioctl.c */
int ide_floppy_ioctl(ide_drive_t *, struct block_device *, fmode_t,
		     unsigned int, unsigned long);

#ifdef CONFIG_IDE_PROC_FS
/* ide-floppy_proc.c */
extern ide_proc_entry_t ide_floppy_proc[];
extern const struct ide_proc_devset ide_floppy_settings[];
#endif
#else
#define ide_floppy_proc		NULL
#define ide_floppy_settings	NULL
#endif

#endif /*__IDE_FLOPPY_H */

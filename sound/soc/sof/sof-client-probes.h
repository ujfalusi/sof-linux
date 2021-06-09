/* SPDX-License-Identifier: (GPL-2.0-only OR BSD-3-Clause) */
/*
 * This file is provided under a dual BSD/GPLv2 license.  When using or
 * redistributing this file, you may do so under either license.
 *
 * Copyright(c) 2021 Intel Corporation. All rights reserved.
 */

#ifndef __SOF_CLIENT_PROBES_H
#define __SOF_CLIENT_PROBES_H

struct snd_compr_stream;
struct snd_compr_tstamp;
struct snd_compr_params;
struct snd_soc_dai;

/* Platform callbacks */
struct sof_probes_host_side_ops {
	int (*assign)(struct snd_compr_stream *cstream,
		      struct snd_soc_dai *dai, void *host_data);
	int (*free)(struct snd_compr_stream *cstream,
		    struct snd_soc_dai *dai, void *host_data);
	int (*set_params)(struct snd_compr_stream *cstream,
			  struct snd_compr_params *params,
			  struct snd_soc_dai *dai, void *host_data);
	int (*trigger)(struct snd_compr_stream *cstream, int cmd,
		       struct snd_soc_dai *dai, void *host_data);
	int (*pointer)(struct snd_compr_stream *cstream,
		       struct snd_compr_tstamp *tstamp,
		       struct snd_soc_dai *dai, void *host_data);
};

struct sof_probes_pdata {
	const struct sof_probes_host_side_ops *ops;
	void *host_data;
};

#endif

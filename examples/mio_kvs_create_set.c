/* -*- C -*- */
/*
 * Copyright: (c) 2020 - 2021 Seagate Technology LLC and/or its its Affiliates,
 * All Rights Reserved
 *
 * This software is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>
#include <stdlib.h>

#include "kvs.h"
#include "helpers.h"

static void create_set_usage(FILE *file, char *prog_name)
{
	fprintf(file, "Usage: %s [OPTION]...\n"
"Create a key/value set.\n"
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"  -k, --kvset         ID       ID of the MIO key/value set \n"
"  -y, --mio_conf_file          MIO YAML configuration file\n"
"  -h, --help                   shows this help text and exit\n"
, prog_name);
}

int main(int argc, char **argv)
{
	int rc;
	struct mio_cmd_kvs_params create_set_params;

	mio_cmd_kvs_args_init(argc, argv, &create_set_params, &create_set_usage);

	rc = mio_init(create_set_params.ckp_conf_fname);
	if (rc < 0) {
		mio_cmd_error("Initialising MIO failed", rc);
		exit(EXIT_FAILURE);
	}

	rc = mio_cmd_kvs_create_set(&create_set_params.ckp_kid);
	if (rc < 0)
		mio_cmd_error("Creating an KVS set failed", rc);

	mio_fini();
	mio_cmd_kvs_args_fini(&create_set_params);
	return rc;
}

/*
 *  Local variables:
 *  c-indentation-style: "K&R"
 *  c-basic-offset: 8
 *  tab-width: 8
 *  fill-column: 80
 *  scroll-step: 1
 *  End:
 */
/*
 * vim: tabstop=8 shiftwidth=8 noexpandtab textwidth=80 nowrap
 */

static int diff_compaction_heuristic; /* experimental */
		DIFF_OPT_SET(options, SUBMODULE_LOG);
		DIFF_OPT_CLR(options, SUBMODULE_LOG);
	if (!strcmp(var, "diff.compactionheuristic")) {
		diff_compaction_heuristic = git_config_bool(var, value);
		return 0;
	}
	int *found_changesp;
	ecbdata.found_changesp = &o->found_changes;
		if (!regexec(word_regex, buffer->ptr + *begin, 1, match, 0)) {
		fprintf(ecbdata->opt->file, "%s", ecbdata->header->buf);
	*(ecbdata->found_changesp) = 1;
		fprintf(ecbdata->opt->file, "%s%s--- %s%s%s\n",
		fprintf(ecbdata->opt->file, "%s%s+++ %s%s%s\n",
			putc('\n', ecbdata->opt->file);
		return;
	}

	if (len < 1) {
		emit_line(ecbdata->opt, reset, reset, line, len);
		if (ecbdata->diff_words
		    && ecbdata->diff_words->type == DIFF_WORDS_PORCELAIN)
			fputs("~\n", ecbdata->opt->file);
			emit_line(ecbdata->opt, context, reset, line, len);
			fputs("~\n", ecbdata->opt->file);
			emit_line(ecbdata->opt, context, reset, line, len);
		emit_line(ecbdata->opt,
			  diff_get_color(ecbdata->color_diff, DIFF_CONTEXT),
		width = term_columns() - options->output_prefix_length;
		if (p->one->sha1_valid && p->two->sha1_valid)
			content_changed = hashcmp(p->one->sha1, p->two->sha1);
			diffcore_count_changes(p->one, p->two, NULL, NULL, 0,
	qsort(dir.files, dir.nr, sizeof(dir.files[0]), dirstat_compare);
	qsort(dir.files, dir.nr, sizeof(dir.files[0]), dirstat_compare);
	if (DIFF_OPT_TST(o, SUBMODULE_LOG) &&
			(!one->mode || S_ISGITLINK(one->mode)) &&
			(!two->mode || S_ISGITLINK(two->mode))) {
				one->sha1, two->sha1, two->dirty_submodule,
	diff_set_mnemonic_prefix(o, "a/", "b/");
	if (DIFF_OPT_TST(o, REVERSE_DIFF)) {
		a_prefix = o->b_prefix;
		b_prefix = o->a_prefix;
	} else {
		a_prefix = o->a_prefix;
		b_prefix = o->b_prefix;
	}

			if (!hashcmp(one->sha1, two->sha1)) {
		ecbdata.found_changesp = &o->found_changes;
	same_contents = !hashcmp(one->sha1, two->sha1);
		hashcpy(spec->sha1, sha1);
		spec->sha1_valid = sha1_valid;
	if (hashcmp(sha1, ce->sha1) || !S_ISREG(ce->ce_mode))
	strbuf_addf(&buf, "Subproject commit %s%s\n", sha1_to_hex(s->sha1), dirty);
	if (!s->sha1_valid ||
	    reuse_worktree_file(s->path, s->sha1, 0)) {
		if (size_only)
			type = sha1_object_info(s->sha1, &s->size);
				die("unable to read %s", sha1_to_hex(s->sha1));
		s->data = read_sha1_file(s->sha1, &type, &s->size);
			die("unable to read %s", sha1_to_hex(s->sha1));
			   const unsigned char *sha1,
	sha1_to_hex_r(temp->hex, sha1);
	    (!one->sha1_valid ||
	     reuse_worktree_file(name, one->sha1, 1))) {
				       (one->sha1_valid ?
					one->sha1 : null_sha1),
				       (one->sha1_valid ?
			if (!one->sha1_valid)
				sha1_to_hex_r(temp->hex, one->sha1);
			       one->sha1, one->mode);
	if (one && two && hashcmp(one->sha1, two->sha1)) {
		strbuf_addf(msg, "%s%sindex %s..", line_prefix, set,
			    find_unique_abbrev(one->sha1, abbrev));
		strbuf_addstr(msg, find_unique_abbrev(two->sha1, abbrev));
		if (!one->sha1_valid) {
				hashcpy(one->sha1, null_sha1);
			if (index_path(one->sha1, one->path, &st, 0))
		hashclr(one->sha1);
	options->ws_error_highlight = WSEH_NEW;
	if (diff_compaction_heuristic)
		DIFF_XDL_SET(options, COMPACTION_HEURISTIC);
		die("--name-only, --name-status, --check and -s are mutually exclusive");
	if (options->abbrev <= 0 || 40 < options->abbrev)
				die("Option '--stat-width' requires a value");
				die("Option '--stat-name-width' requires a value");
				die("Option '--stat-graph-width' requires a value");
				die("Option '--stat-count' requires a value");
static int parse_one_token(const char **arg, const char *token)
	const char *rest;
	if (skip_prefix(*arg, token, &rest) && (!*rest || *rest == ',')) {
		*arg = rest;
		return 1;
	}
	return 0;
}
static int parse_ws_error_highlight(struct diff_options *opt, const char *arg)
{
	const char *orig_arg = arg;
	unsigned val = 0;
	while (*arg) {
		if (parse_one_token(&arg, "none"))
			val = 0;
		else if (parse_one_token(&arg, "default"))
			val = WSEH_NEW;
		else if (parse_one_token(&arg, "all"))
			val = WSEH_NEW | WSEH_OLD | WSEH_CONTEXT;
		else if (parse_one_token(&arg, "new"))
			val |= WSEH_NEW;
		else if (parse_one_token(&arg, "old"))
			val |= WSEH_OLD;
		else if (parse_one_token(&arg, "context"))
			val |= WSEH_CONTEXT;
		else {
			error("unknown value after ws-error-highlight=%.*s",
			      (int)(arg - orig_arg), orig_arg);
			return 0;
		}
		if (*arg)
			arg++;
	else if (!strcmp(arg, "--compaction-heuristic"))
		DIFF_XDL_SET(options, COMPACTION_HEURISTIC);
	else if (!strcmp(arg, "--no-compaction-heuristic"))
		DIFF_XDL_CLR(options, COMPACTION_HEURISTIC);
		DIFF_OPT_SET(options, SUBMODULE_LOG);
		return parse_ws_error_highlight(options, arg);
/* This is different from find_unique_abbrev() in that
 * it stuffs the result with dots for alignment.
 */
const char *diff_unique_abbrev(const unsigned char *sha1, int len)
	if (len == 40)
		return sha1_to_hex(sha1);
	abbrev = find_unique_abbrev(sha1, len);
	if (abblen < 37) {
		static char hex[41];
	return sha1_to_hex(sha1);
			diff_unique_abbrev(p->one->sha1, opt->abbrev));
		fprintf(opt->file, "%s ", diff_unique_abbrev(p->two->sha1, opt->abbrev));
	if (one->sha1_valid && two->sha1_valid &&
	    !hashcmp(one->sha1, two->sha1) &&
	if (!one->sha1_valid && !two->sha1_valid)
		s->sha1_valid ? sha1_to_hex(s->sha1) : "");
		else if (hashcmp(p->one->sha1, p->two->sha1) ||
			 is_null_sha1(p->one->sha1))
static int diff_get_patch_id(struct diff_options *options, unsigned char *sha1)
		if (fill_mmfile(&mf1, p->one) < 0 ||
				fill_mmfile(&mf2, p->two) < 0)
			return error("unable to read files to diff");
			git_SHA1_Update(&ctx, sha1_to_hex(p->one->sha1), 40);
			git_SHA1_Update(&ctx, sha1_to_hex(p->two->sha1), 40);
int diff_flush_patch_id(struct diff_options *options, unsigned char *sha1)
	int result = diff_get_patch_id(options, sha1);
"inexact rename detection was skipped due to too many files.";
"only found copies from modified paths due to too many files.";
"you may want to set your %s variable to at least "
"%d and retry the command.";
		warning(degrade_cc_to_c_warning);
		warning(rename_limit_warning);
		warning(rename_limit_advice, varname, needed);
	    (p->one->sha1_valid && p->two->sha1_valid) ||
	qsort(q->queue, q->nr, sizeof(q->queue[0]), diffnamecmp);
		unsigned tmp;
		const unsigned char *tmp_c;
		tmp = old_mode; old_mode = new_mode; new_mode = tmp;
		tmp_c = old_sha1; old_sha1 = new_sha1; new_sha1 = tmp_c;
		tmp = old_sha1_valid; old_sha1_valid = new_sha1_valid;
			new_sha1_valid = tmp;
		tmp = old_dirty_submodule; old_dirty_submodule = new_dirty_submodule;
			new_dirty_submodule = tmp;
	if (driver->textconv_cache && df->sha1_valid) {
		*outbuf = notes_cache_get(driver->textconv_cache, df->sha1,
	if (driver->textconv_cache && df->sha1_valid) {
		notes_cache_put(driver->textconv_cache, df->sha1, *outbuf,
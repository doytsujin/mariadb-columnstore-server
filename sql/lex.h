/* Copyright (C) 2000-2002 MySQL AB

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */


/* This file includes all reserved words and functions */

#include "lex_symbol.h"

/* We don't want to include sql_yacc.h into gen_lex_hash */
SYM_GROUP sym_group_common= {"", ""};
SYM_GROUP sym_group_geom= {"Spatial extentions", "HAVE_SPATIAL"};
SYM_GROUP sym_group_rtree= {"RTree keys", "HAVE_RTREE_KEYS"};

#ifdef NO_YACC_SYMBOLS
#define SYM_OR_NULL(A) 0
#else
#define SYM_OR_NULL(A) A
#endif

#define SYM(A) SYM_OR_NULL(A),0,0,&sym_group_common
#define F_SYM(A) SYM_OR_NULL(A)

#define CREATE_FUNC(A) (void *)(SYM_OR_NULL(A)), &sym_group_common

#ifdef HAVE_SPATIAL
#define CREATE_FUNC_GEOM(A) (void *)(SYM_OR_NULL(A)), &sym_group_geom
#else
#define CREATE_FUNC_GEOM(A) 0, &sym_group_geom
#endif

/*
  Symbols are broken into separated arrays to allow field names with
  same name as functions.
  These are kept sorted for human lookup (the symbols are hashed).
*/

static SYMBOL symbols[] = {
  { "&&",		SYM(AND_SYM)},
  { "<",		SYM(LT)},
  { "<=",		SYM(LE)},
  { "<>",		SYM(NE)},
  { "!=",		SYM(NE)},
  { "=",		SYM(EQ)},
  { ">",		SYM(GT_SYM)},
  { ">=",		SYM(GE)},
  { "<<",		SYM(SHIFT_LEFT)},
  { ">>",		SYM(SHIFT_RIGHT)},
  { "<=>",		SYM(EQUAL_SYM)},
  { "ACTION",		SYM(ACTION)},
  { "ADD",		SYM(ADD)},
  { "AFTER",		SYM(AFTER_SYM)},
  { "AGAINST",          SYM(AGAINST)},
  { "AGGREGATE",	SYM(AGGREGATE_SYM)},
  { "ALL",		SYM(ALL)},
  { "ALGORITHM",	SYM(ALGORITHM_SYM)},
  { "ALTER",		SYM(ALTER)},
  { "ANALYZE",		SYM(ANALYZE_SYM)},
  { "AND",		SYM(AND_SYM)},
  { "ANY",              SYM(ANY_SYM)},
  { "AS",		SYM(AS)},
  { "ASC",		SYM(ASC)},
  { "ASCII",		SYM(ASCII_SYM)},
  { "ASENSITIVE",       SYM(ASENSITIVE_SYM)},
  { "AUTO_INCREMENT",	SYM(AUTO_INC)},
  { "AVG",		SYM(AVG_SYM)},
  { "AVG_ROW_LENGTH",	SYM(AVG_ROW_LENGTH)},
  { "BACKUP",	        SYM(BACKUP_SYM)},
  { "BDB",              SYM(BERKELEY_DB_SYM)},
  { "BEFORE",	        SYM(BEFORE_SYM)},
  { "BEGIN",	        SYM(BEGIN_SYM)},
  { "BERKELEYDB",       SYM(BERKELEY_DB_SYM)},
  { "BETWEEN",		SYM(BETWEEN_SYM)},
  { "BIGINT",		SYM(BIGINT)},
  { "BINARY",		SYM(BINARY)},
  { "BINLOG",		SYM(BINLOG_SYM)},
  { "BIT",		SYM(BIT_SYM)},
  { "BLOB",		SYM(BLOB_SYM)},
  { "BOOL",		SYM(BOOL_SYM)},
  { "BOOLEAN",		SYM(BOOLEAN_SYM)},
  { "BOTH",		SYM(BOTH)},
  { "BTREE",		SYM(BTREE_SYM)},
  { "BY",		SYM(BY)},
  { "BYTE",		SYM(BYTE_SYM)},
  { "CACHE",		SYM(CACHE_SYM)},
  { "CALL",             SYM(CALL_SYM)},
  { "CASCADE",		SYM(CASCADE)},
  { "CASCADED",         SYM(CASCADED)},
  { "CASE",		SYM(CASE_SYM)},
  { "CHANGE",		SYM(CHANGE)},
  { "CHANGED",		SYM(CHANGED)},
  { "CHAR",		SYM(CHAR_SYM)},
  { "CHARACTER",	SYM(CHAR_SYM)},
  { "CHARSET",		SYM(CHARSET)},
  { "CHECK",		SYM(CHECK_SYM)},
  { "CHECKSUM",		SYM(CHECKSUM_SYM)},
  { "CIPHER",		SYM(CIPHER_SYM)},
  { "CLIENT",		SYM(CLIENT_SYM)},
  { "CLOSE",		SYM(CLOSE_SYM)},
  { "COLLATE",		SYM(COLLATE_SYM)},
  { "COLLATION",	SYM(COLLATION_SYM)},
  { "COLUMN",		SYM(COLUMN_SYM)},
  { "COLUMNS",		SYM(COLUMNS)},
  { "COMMENT",		SYM(COMMENT_SYM)},
  { "COMMIT",		SYM(COMMIT_SYM)},
  { "COMMITTED",	SYM(COMMITTED_SYM)},
  { "COMPRESSED",	SYM(COMPRESSED_SYM)},
  { "CONCURRENT",	SYM(CONCURRENT)},
  { "CONDITION",        SYM(CONDITION_SYM)},
  { "CONNECTION",       SYM(CONNECTION_SYM)},
  { "CONSTRAINT",	SYM(CONSTRAINT)},
  { "CONTINUE",         SYM(CONTINUE_SYM)},
  { "CONVERT",		SYM(CONVERT_SYM)},
  { "CREATE",		SYM(CREATE)},
  { "CROSS",		SYM(CROSS)},
  { "CUBE",		SYM(CUBE_SYM)},
  { "CURRENT_DATE",	SYM(CURDATE)},
  { "CURRENT_TIME",	SYM(CURTIME)},
  { "CURRENT_TIMESTAMP", SYM(NOW_SYM)},
  { "CURRENT_USER",	SYM(CURRENT_USER)},
  { "CURSOR",           SYM(CURSOR_SYM)},
  { "DATA",		SYM(DATA_SYM)},
  { "DATABASE",		SYM(DATABASE)},
  { "DATABASES",	SYM(DATABASES)},
  { "DATE",		SYM(DATE_SYM)},
  { "DATETIME",		SYM(DATETIME)},
  { "DAY",		SYM(DAY_SYM)},
  { "DAY_HOUR",		SYM(DAY_HOUR_SYM)},
  { "DAY_MICROSECOND",	SYM(DAY_MICROSECOND_SYM)},
  { "DAY_MINUTE",	SYM(DAY_MINUTE_SYM)},
  { "DAY_SECOND",	SYM(DAY_SECOND_SYM)},
  { "DEALLOCATE",       SYM(DEALLOCATE_SYM)},     
  { "DEC",		SYM(DECIMAL_SYM)},
  { "DECIMAL",		SYM(DECIMAL_SYM)},
  { "DECLARE",          SYM(DECLARE_SYM)},
  { "DEFAULT",		SYM(DEFAULT)},
  { "DEFINER",          SYM(DEFINER_SYM)},
  { "DELAYED",		SYM(DELAYED_SYM)},
  { "DELAY_KEY_WRITE",	SYM(DELAY_KEY_WRITE_SYM)},
  { "DELETE",		SYM(DELETE_SYM)},
  { "DESC",		SYM(DESC)},
  { "DESCRIBE",		SYM(DESCRIBE)},
  { "DES_KEY_FILE",	SYM(DES_KEY_FILE)},
  { "DETERMINISTIC",    SYM(DETERMINISTIC_SYM)},
  { "DIRECTORY",	SYM(DIRECTORY_SYM)},
  { "DISABLE",		SYM(DISABLE_SYM)},
  { "DISCARD",		SYM(DISCARD)},
  { "DISTINCT",		SYM(DISTINCT)},
  { "DISTINCTROW",	SYM(DISTINCT)},	/* Access likes this */
  { "DIV",		SYM(DIV_SYM)},
  { "DO",		SYM(DO_SYM)},
  { "DOUBLE",		SYM(DOUBLE_SYM)},
  { "DROP",		SYM(DROP)},
  { "DUAL",		SYM(DUAL_SYM)},
  { "DUMPFILE",		SYM(DUMPFILE)},
  { "DUPLICATE",	SYM(DUPLICATE_SYM)},
  { "DYNAMIC",		SYM(DYNAMIC_SYM)},
  { "ELSE",             SYM(ELSE)},
  { "ELSEIF",           SYM(ELSEIF_SYM)},
  { "ENABLE",		SYM(ENABLE_SYM)},
  { "ENCLOSED",		SYM(ENCLOSED)},
  { "END",		SYM(END)},
  { "ENGINE",		SYM(ENGINE_SYM)},
  { "ENGINES",		SYM(ENGINES_SYM)},
  { "ENUM",		SYM(ENUM)},
  { "ERRORS",		SYM(ERRORS)},
  { "ESCAPE",		SYM(ESCAPE_SYM)},
  { "ESCAPED",		SYM(ESCAPED)},
  { "EVENTS",		SYM(EVENTS_SYM)},
  { "EXECUTE",		SYM(EXECUTE_SYM)},
  { "EXISTS",		SYM(EXISTS)},
  { "EXIT",             SYM(EXIT_SYM)},
  { "EXPANSION",	SYM(EXPANSION_SYM)},
  { "EXPLAIN",		SYM(DESCRIBE)},
  { "EXTENDED",		SYM(EXTENDED_SYM)},
  { "FALSE",		SYM(FALSE_SYM)},
  { "FAST",		SYM(FAST_SYM)},
  { "FETCH",            SYM(FETCH_SYM)},
  { "FIELDS",		SYM(COLUMNS)},
  { "FILE",		SYM(FILE_SYM)},
  { "FIRST",		SYM(FIRST_SYM)},
  { "FIXED",		SYM(FIXED_SYM)},
  { "FLOAT",		SYM(FLOAT_SYM)},
  { "FLOAT4",		SYM(FLOAT_SYM)},
  { "FLOAT8",		SYM(DOUBLE_SYM)},
  { "FLUSH",		SYM(FLUSH_SYM)},
  { "FOR",		SYM(FOR_SYM)},
  { "FORCE",		SYM(FORCE_SYM)},
  { "FOREIGN",		SYM(FOREIGN)},
  { "FOUND",            SYM(FOUND_SYM)},
  { "FRAC_SECOND",      SYM(FRAC_SECOND_SYM)},
  { "FROM",		SYM(FROM)},
  { "FULL",		SYM(FULL)},
  { "FULLTEXT",		SYM(FULLTEXT_SYM)},
  { "FUNCTION",		SYM(FUNCTION_SYM)},
  { "GEOMETRY",		SYM(GEOMETRY_SYM)},
  { "GEOMETRYCOLLECTION",SYM(GEOMETRYCOLLECTION)},
  { "GET_FORMAT",       SYM(GET_FORMAT)},
  { "GLOBAL",		SYM(GLOBAL_SYM)},
  { "GOTO",             SYM(GOTO_SYM)},
  { "GRANT",		SYM(GRANT)},
  { "GRANTS",	        SYM(GRANTS)},
  { "GROUP",		SYM(GROUP)},
  { "HANDLER",		SYM(HANDLER_SYM)},
  { "HASH",		SYM(HASH_SYM)},
  { "HAVING",		SYM(HAVING)},
  { "HELP",		SYM(HELP_SYM)},
  { "HIGH_PRIORITY",	SYM(HIGH_PRIORITY)},
  { "HOSTS",		SYM(HOSTS_SYM)},
  { "HOUR",		SYM(HOUR_SYM)},
  { "HOUR_MICROSECOND",	SYM(HOUR_MICROSECOND_SYM)},
  { "HOUR_MINUTE",	SYM(HOUR_MINUTE_SYM)},
  { "HOUR_SECOND",	SYM(HOUR_SECOND_SYM)},
  { "IDENTIFIED",	SYM(IDENTIFIED_SYM)},
  { "IF",		SYM(IF)},
  { "IGNORE",		SYM(IGNORE_SYM)},
  { "IMPORT",		SYM(IMPORT)},
  { "IN",		SYM(IN_SYM)},
  { "INDEX",		SYM(INDEX_SYM)},
  { "INDEXES",		SYM(INDEXES)},
  { "INFILE",		SYM(INFILE)},
  { "INNER",		SYM(INNER_SYM)},
  { "INNOBASE",		SYM(INNOBASE_SYM)},
  { "INNODB",		SYM(INNOBASE_SYM)},
  { "INOUT",            SYM(INOUT_SYM)},
  { "INSENSITIVE",      SYM(INSENSITIVE_SYM)},
  { "INSERT",		SYM(INSERT)},
  { "INSERT_METHOD",    SYM(INSERT_METHOD)},
  { "INT",		SYM(INT_SYM)},
  { "INT1",		SYM(TINYINT)},
  { "INT2",		SYM(SMALLINT)},
  { "INT3",		SYM(MEDIUMINT)},
  { "INT4",		SYM(INT_SYM)},
  { "INT8",		SYM(BIGINT)},
  { "INTEGER",		SYM(INT_SYM)},
  { "INTERVAL",		SYM(INTERVAL_SYM)},
  { "INTO",		SYM(INTO)},
  { "IO_THREAD",        SYM(RELAY_THREAD)},
  { "IS",		SYM(IS)},
  { "ISOLATION",	SYM(ISOLATION)},
  { "ISSUER",		SYM(ISSUER_SYM)},
  { "ITERATE",          SYM(ITERATE_SYM)},
  { "INVOKER",          SYM(INVOKER_SYM)},
  { "JOIN",		SYM(JOIN_SYM)},
  { "KEY",		SYM(KEY_SYM)},
  { "KEYS",		SYM(KEYS)},
  { "KILL",		SYM(KILL_SYM)},
  { "LABEL",            SYM(LABEL_SYM)},
  { "LANGUAGE",         SYM(LANGUAGE_SYM)},
  { "LAST",		SYM(LAST_SYM)},
  { "LEADING",		SYM(LEADING)},
  { "LEAVE",            SYM(LEAVE_SYM)},
  { "LEAVES",		SYM(LEAVES)},
  { "LEFT",		SYM(LEFT)},
  { "LEVEL",		SYM(LEVEL_SYM)},
  { "LIKE",		SYM(LIKE)},
  { "LIMIT",		SYM(LIMIT)},
  { "LINES",		SYM(LINES)},
  { "LINESTRING",	SYM(LINESTRING)},
  { "LOAD",		SYM(LOAD)},
  { "LOCAL",		SYM(LOCAL_SYM)},
  { "LOCALTIME",	SYM(NOW_SYM)},
  { "LOCALTIMESTAMP",	SYM(NOW_SYM)},
  { "LOCK",		SYM(LOCK_SYM)},
  { "LOCKS",		SYM(LOCKS_SYM)},
  { "LOGS",		SYM(LOGS_SYM)},
  { "LONG",		SYM(LONG_SYM)},
  { "LONGBLOB",		SYM(LONGBLOB)},
  { "LONGTEXT",		SYM(LONGTEXT)},
  { "LOOP",             SYM(LOOP_SYM)},
  { "LOW_PRIORITY",	SYM(LOW_PRIORITY)},
  { "MASTER",           SYM(MASTER_SYM)},
  { "MASTER_CONNECT_RETRY",           SYM(MASTER_CONNECT_RETRY_SYM)},
  { "MASTER_HOST",           SYM(MASTER_HOST_SYM)},
  { "MASTER_LOG_FILE",           SYM(MASTER_LOG_FILE_SYM)},
  { "MASTER_LOG_POS",           SYM(MASTER_LOG_POS_SYM)},
  { "MASTER_PASSWORD",           SYM(MASTER_PASSWORD_SYM)},
  { "MASTER_PORT",           SYM(MASTER_PORT_SYM)},
  { "MASTER_SERVER_ID",           SYM(MASTER_SERVER_ID_SYM)},
  { "MASTER_SSL",       SYM(MASTER_SSL_SYM)},
  { "MASTER_SSL_CA",    SYM(MASTER_SSL_CA_SYM)},
  { "MASTER_SSL_CAPATH",SYM(MASTER_SSL_CAPATH_SYM)},
  { "MASTER_SSL_CERT",  SYM(MASTER_SSL_CERT_SYM)},
  { "MASTER_SSL_CIPHER",SYM(MASTER_SSL_CIPHER_SYM)},
  { "MASTER_SSL_KEY",   SYM(MASTER_SSL_KEY_SYM)},
  { "MASTER_USER",           SYM(MASTER_USER_SYM)},
  { "MATCH",		SYM(MATCH)},
  { "MAX_CONNECTIONS_PER_HOUR", SYM(MAX_CONNECTIONS_PER_HOUR)},
  { "MAX_QUERIES_PER_HOUR", SYM(MAX_QUERIES_PER_HOUR)},
  { "MAX_ROWS",		SYM(MAX_ROWS)},
  { "MAX_UPDATES_PER_HOUR", SYM(MAX_UPDATES_PER_HOUR)},
  { "MEDIUM",		SYM(MEDIUM_SYM)},
  { "MEDIUMBLOB",	SYM(MEDIUMBLOB)},
  { "MEDIUMINT",	SYM(MEDIUMINT)},
  { "MEDIUMTEXT",	SYM(MEDIUMTEXT)},
  { "MERGE",		SYM(MERGE_SYM)},
  { "MICROSECOND",	SYM(MICROSECOND_SYM)},
  { "MIDDLEINT",	SYM(MEDIUMINT)},	/* For powerbuilder */
  { "MINUTE",		SYM(MINUTE_SYM)},
  { "MINUTE_MICROSECOND", SYM(MINUTE_MICROSECOND_SYM)},
  { "MINUTE_SECOND",	SYM(MINUTE_SECOND_SYM)},
  { "MIN_ROWS",		SYM(MIN_ROWS)},
  { "MOD",		SYM(MOD_SYM)},
  { "MODE",		SYM(MODE_SYM)},
  { "MODIFY",		SYM(MODIFY_SYM)},
  { "MONTH",		SYM(MONTH_SYM)},
  { "MULTILINESTRING",	SYM(MULTILINESTRING)},
  { "MULTIPOINT",	SYM(MULTIPOINT)},
  { "MULTIPOLYGON",	SYM(MULTIPOLYGON)},
  { "NAME",             SYM(NAME_SYM)},
  { "NAMES",		SYM(NAMES_SYM)},
  { "NATIONAL",		SYM(NATIONAL_SYM)},
  { "NATURAL",		SYM(NATURAL)},
  { "NDB",              SYM(NDBCLUSTER_SYM)},
  { "NDBCLUSTER",       SYM(NDBCLUSTER_SYM)},
  { "NCHAR",		SYM(NCHAR_SYM)},
  { "NEW",              SYM(NEW_SYM)},
  { "NEXT",		SYM(NEXT_SYM)},
  { "NO",		SYM(NO_SYM)},
  { "NONE",		SYM(NONE_SYM)},
  { "NOT",		SYM(NOT)},
  { "NO_WRITE_TO_BINLOG",  SYM(NO_WRITE_TO_BINLOG)},
  { "NULL",		SYM(NULL_SYM)},
  { "NUMERIC",		SYM(NUMERIC_SYM)},
  { "NVARCHAR",		SYM(NVARCHAR_SYM)},
  { "OFFSET",		SYM(OFFSET_SYM)},
  { "OLD_PASSWORD",	SYM(OLD_PASSWORD)},
  { "ON",		SYM(ON)},
  { "ONE_SHOT",		SYM(ONE_SHOT_SYM)},
  { "OPEN",		SYM(OPEN_SYM)},
  { "OPTIMIZE",		SYM(OPTIMIZE)},
  { "OPTION",		SYM(OPTION)},
  { "OPTIONALLY",	SYM(OPTIONALLY)},
  { "OR",		SYM(OR_SYM)},
  { "ORDER",		SYM(ORDER_SYM)},
  { "OUT",              SYM(OUT_SYM)},
  { "OUTER",		SYM(OUTER)},
  { "OUTFILE",		SYM(OUTFILE)},
  { "PACK_KEYS",	SYM(PACK_KEYS_SYM)},
  { "PARTIAL",		SYM(PARTIAL)},
  { "PASSWORD",		SYM(PASSWORD)},
  { "POINT",		SYM(POINT_SYM)},
  { "POLYGON",		SYM(POLYGON)},
  { "PRECISION",	SYM(PRECISION)},
  { "PREPARE",          SYM(PREPARE_SYM)},
  { "PREV",		SYM(PREV_SYM)},
  { "PRIMARY",		SYM(PRIMARY_SYM)},
  { "PRIVILEGES",	SYM(PRIVILEGES)},
  { "PROCEDURE",	SYM(PROCEDURE)},
  { "PROCESS"	,	SYM(PROCESS)},
  { "PROCESSLIST",	SYM(PROCESSLIST_SYM)},
  { "PURGE",		SYM(PURGE)},
  { "QUARTER",          SYM(QUARTER_SYM)},
  { "QUERY",		SYM(QUERY_SYM)},
  { "QUICK",	        SYM(QUICK)},
  { "RAID0",		SYM(RAID_0_SYM)},
  { "RAID_CHUNKS",	SYM(RAID_CHUNKS)},
  { "RAID_CHUNKSIZE",	SYM(RAID_CHUNKSIZE)},
  { "RAID_TYPE",	SYM(RAID_TYPE)},
  { "READ",		SYM(READ_SYM)},
  { "REAL",		SYM(REAL)},
  { "REFERENCES",	SYM(REFERENCES)},
  { "REGEXP",		SYM(REGEXP)},
  { "RELAY_LOG_FILE",   SYM(RELAY_LOG_FILE_SYM)},
  { "RELAY_LOG_POS",    SYM(RELAY_LOG_POS_SYM)},
  { "RELAY_THREAD",     SYM(RELAY_THREAD)},
  { "RELOAD",		SYM(RELOAD)},
  { "RENAME",		SYM(RENAME)},
  { "REPAIR",		SYM(REPAIR)},
  { "REPEATABLE",	SYM(REPEATABLE_SYM)},
  { "REPLACE",		SYM(REPLACE)},
  { "REPLICATION",	SYM(REPLICATION)},
  { "REPEAT",           SYM(REPEAT_SYM)},
  { "REQUIRE",	        SYM(REQUIRE_SYM)},
  { "RESET",		SYM(RESET_SYM)},
  { "RESTORE",		SYM(RESTORE_SYM)},
  { "RESTRICT",		SYM(RESTRICT)},
  { "RETURN",           SYM(RETURN_SYM)},
  { "RETURNS",		SYM(RETURNS_SYM)},
  { "REVOKE",		SYM(REVOKE)},
  { "RIGHT",		SYM(RIGHT)},
  { "RLIKE",		SYM(REGEXP)},	/* Like in mSQL2 */
  { "ROLLBACK",		SYM(ROLLBACK_SYM)},
  { "ROLLUP",		SYM(ROLLUP_SYM)},
  { "ROW",		SYM(ROW_SYM)},
  { "ROWS",		SYM(ROWS_SYM)},
  { "ROW_FORMAT",	SYM(ROW_FORMAT_SYM)},
  { "RTREE",		SYM(RTREE_SYM)},
  { "SAVEPOINT",	SYM(SAVEPOINT_SYM)},
  { "SECOND",		SYM(SECOND_SYM)},
  { "SECOND_MICROSECOND", SYM(SECOND_MICROSECOND_SYM)},
  { "SECURITY",         SYM(SECURITY_SYM)},
  { "SELECT",		SYM(SELECT_SYM)},
  { "SENSITIVE",        SYM(SENSITIVE_SYM)},
  { "SEPARATOR",	SYM(SEPARATOR_SYM)},
  { "SERIAL",		SYM(SERIAL_SYM)},
  { "SERIALIZABLE",	SYM(SERIALIZABLE_SYM)},
  { "SESSION",		SYM(SESSION_SYM)},
  { "SET",		SYM(SET)},
  { "SHARE",		SYM(SHARE_SYM)},
  { "SHOW",		SYM(SHOW)},
  { "SHUTDOWN",		SYM(SHUTDOWN)},
  { "SIGNED",		SYM(SIGNED_SYM)},
  { "SIMPLE",		SYM(SIMPLE_SYM)},
  { "SLAVE",            SYM(SLAVE)},
  { "SMALLINT",		SYM(SMALLINT)},
  { "SOME",             SYM(ANY_SYM)},
  { "SONAME",		SYM(UDF_SONAME_SYM)},
  { "SOUNDS",		SYM(SOUNDS_SYM)},
  { "SPATIAL",		SYM(SPATIAL_SYM)},
  { "SPECIFIC",         SYM(SPECIFIC_SYM)},
  { "SQL",              SYM(SQL_SYM)},
  { "SQLEXCEPTION",     SYM(SQLEXCEPTION_SYM)},
  { "SQLSTATE",         SYM(SQLSTATE_SYM)},
  { "SQLWARNING",       SYM(SQLWARNING_SYM)},
  { "SQL_BIG_RESULT",	SYM(SQL_BIG_RESULT)},
  { "SQL_BUFFER_RESULT", SYM(SQL_BUFFER_RESULT)},
  { "SQL_CACHE",        SYM(SQL_CACHE_SYM)},
  { "SQL_CALC_FOUND_ROWS", SYM(SQL_CALC_FOUND_ROWS)},
  { "SQL_NO_CACHE",	SYM(SQL_NO_CACHE_SYM)},
  { "SQL_SMALL_RESULT", SYM(SQL_SMALL_RESULT)},
  { "SQL_THREAD",	SYM(SQL_THREAD)},
  { "SQL_TSI_FRAC_SECOND", SYM(FRAC_SECOND_SYM)},
  { "SQL_TSI_SECOND",   SYM(SECOND_SYM)},
  { "SQL_TSI_MINUTE",   SYM(MINUTE_SYM)},
  { "SQL_TSI_HOUR",     SYM(HOUR_SYM)},
  { "SQL_TSI_DAY",      SYM(DAY_SYM)},
  { "SQL_TSI_WEEK",     SYM(WEEK_SYM)},
  { "SQL_TSI_MONTH",    SYM(MONTH_SYM)},
  { "SQL_TSI_QUARTER",  SYM(QUARTER_SYM)},
  { "SQL_TSI_YEAR",     SYM(YEAR_SYM)},
  { "SSL",		SYM(SSL_SYM)},
  { "START",		SYM(START_SYM)},
  { "STARTING",		SYM(STARTING)},
  { "STATUS",		SYM(STATUS_SYM)},
  { "STOP",		SYM(STOP_SYM)},
  { "STORAGE",		SYM(STORAGE_SYM)},
  { "STRAIGHT_JOIN",	SYM(STRAIGHT_JOIN)},
  { "STRING",		SYM(STRING_SYM)},
  { "STRIPED",		SYM(RAID_STRIPED_SYM)},
  { "SUBJECT",		SYM(SUBJECT_SYM)},
  { "SUPER",		SYM(SUPER_SYM)},
  { "TABLE",		SYM(TABLE_SYM)},
  { "TABLES",		SYM(TABLES)},
  { "TABLESPACE",	SYM(TABLESPACE)},
  { "TEMPORARY",	SYM(TEMPORARY)},
  { "TEMPTABLE",	SYM(TEMPTABLE_SYM)},
  { "TERMINATED",	SYM(TERMINATED)},
  { "TEXT",		SYM(TEXT_SYM)},
  { "THEN",		SYM(THEN_SYM)},
  { "TIME",		SYM(TIME_SYM)},
  { "TIMESTAMP",	SYM(TIMESTAMP)},
  { "TIMESTAMPADD",     SYM(TIMESTAMP_ADD)},
  { "TIMESTAMPDIFF",    SYM(TIMESTAMP_DIFF)},
  { "TINYBLOB",		SYM(TINYBLOB)},
  { "TINYINT",		SYM(TINYINT)},
  { "TINYTEXT",		SYM(TINYTEXT)},
  { "TO",		SYM(TO_SYM)},
  { "TRAILING",		SYM(TRAILING)},
  { "TRANSACTION",	SYM(TRANSACTION_SYM)},
  { "TRUE",		SYM(TRUE_SYM)},
  { "TRUNCATE",		SYM(TRUNCATE_SYM)},
  { "TYPE",		SYM(TYPE_SYM)},
  { "TYPES",		SYM(TYPES_SYM)},
  { "UNCOMMITTED",	SYM(UNCOMMITTED_SYM)},
  { "UNDO",             SYM(UNDO_SYM)},
  { "UNICODE",	        SYM(UNICODE_SYM)},
  { "UNION",	        SYM(UNION_SYM)},
  { "UNIQUE",		SYM(UNIQUE_SYM)},
  { "UNLOCK",		SYM(UNLOCK_SYM)},
  { "UNSIGNED",		SYM(UNSIGNED)},
  { "UNTIL",		SYM(UNTIL_SYM)},
  { "UPDATE",		SYM(UPDATE_SYM)},
  { "USAGE",		SYM(USAGE)},
  { "USE",		SYM(USE_SYM)},
  { "USER",		SYM(USER)},
  { "USER_RESOURCES",	SYM(RESOURCES)},
  { "USE_FRM",		SYM(USE_FRM)},
  { "USING",		SYM(USING)},
  { "UTC_DATE",         SYM(UTC_DATE_SYM)},
  { "UTC_TIME",         SYM(UTC_TIME_SYM)},
  { "UTC_TIMESTAMP",    SYM(UTC_TIMESTAMP_SYM)},
  { "VALUE",		SYM(VALUE_SYM)},
  { "VALUES",		SYM(VALUES)},
  { "VARBINARY",	SYM(VARBINARY)},
  { "VARCHAR",		SYM(VARCHAR)},
  { "VARCHARACTER",	SYM(VARCHAR)},
  { "VARIABLES",	SYM(VARIABLES)},
  { "VARYING",		SYM(VARYING)},
  { "WARNINGS",		SYM(WARNINGS)},
  { "WEEK",		SYM(WEEK_SYM)},
  { "WHEN",		SYM(WHEN_SYM)},
  { "WHERE",		SYM(WHERE)},
  { "WHILE",            SYM(WHILE_SYM)},
  { "VIEW",		SYM(VIEW_SYM)},
  { "WITH",		SYM(WITH)},
  { "WORK",		SYM(WORK_SYM)},
  { "WRITE",		SYM(WRITE_SYM)},
  { "X509",		SYM(X509_SYM)},
  { "XOR",		SYM(XOR)},
  { "YEAR",		SYM(YEAR_SYM)},
  { "YEAR_MONTH",	SYM(YEAR_MONTH_SYM)},
  { "ZEROFILL",		SYM(ZEROFILL)},
  { "||",		SYM(OR_OR_CONCAT)}
};


static SYMBOL sql_functions[] = {
  { "ABS",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_abs)},
  { "ACOS",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_acos)},
  { "ADDDATE",		SYM(ADDDATE_SYM)},
  { "ADDTIME",		F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_addtime)},
  { "AES_ENCRYPT",      F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_aes_encrypt)},
  { "AES_DECRYPT",      F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_aes_decrypt)},
  { "AREA",		F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_area)},
  { "ASIN",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_asin)},
  { "ASBINARY",		F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_as_wkb)},
  { "ASTEXT",		F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_as_wkt)},
  { "ASWKB",		F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_as_wkb)},
  { "ASWKT",		F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_as_wkt)},
  { "ATAN",		SYM(ATAN)},
  { "ATAN2",		SYM(ATAN)},
  { "BENCHMARK",	SYM(BENCHMARK_SYM)},
  { "BIN",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_bin)},
  { "BIT_COUNT",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_bit_count)},
  { "BIT_OR",		SYM(BIT_OR)},
  { "BIT_AND",		SYM(BIT_AND)},
  { "BIT_XOR",		SYM(BIT_XOR)},
  { "CAST",		SYM(CAST_SYM)},
  { "CEIL",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_ceiling)},
  { "CEILING",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_ceiling)},
  { "BIT_LENGTH",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_bit_length)},
  { "CENTROID",		F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_centroid)},
  { "CHAR_LENGTH",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_char_length)},
  { "CHARACTER_LENGTH", F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_char_length)},
  { "COALESCE",		SYM(COALESCE)},
  { "COERCIBILITY",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_coercibility)},
  { "COMPRESS",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_compress)},
  { "CONCAT",		SYM(CONCAT)},
  { "CONCAT_WS",	SYM(CONCAT_WS)},
  { "CONNECTION_ID",	F_SYM(FUNC_ARG0),0,CREATE_FUNC(create_func_connection_id)},
  { "CONTAINS",		F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_contains)},
  { "CONV",		F_SYM(FUNC_ARG3),0,CREATE_FUNC(create_func_conv)},
  { "CONVERT_TZ",	SYM(CONVERT_TZ_SYM)},
  { "COUNT",		SYM(COUNT_SYM)},
  { "COS",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_cos)},
  { "COT",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_cot)},
  { "CRC32",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_crc32)},
  { "CROSSES",		F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_crosses)},
  { "CURDATE",		SYM(CURDATE)},
  { "CURTIME",		SYM(CURTIME)},
  { "DATE_ADD",		SYM(DATE_ADD_INTERVAL)},
  { "DATEDIFF",		F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_datediff)},
  { "DATE_FORMAT",	F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_date_format)},
  { "DATE_SUB",		SYM(DATE_SUB_INTERVAL)},
  { "DAYNAME",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_dayname)},
  { "DAYOFMONTH",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_dayofmonth)},
  { "DAYOFWEEK",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_dayofweek)},
  { "DAYOFYEAR",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_dayofyear)},
  { "DECODE",		SYM(DECODE_SYM)},
  { "DEGREES",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_degrees)},
  { "DES_ENCRYPT",	SYM(DES_ENCRYPT_SYM)},
  { "DES_DECRYPT",	SYM(DES_DECRYPT_SYM)},
  { "DIMENSION",	F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_dimension)},
  { "DISJOINT",		F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_disjoint)},
  { "ELT",		SYM(ELT_FUNC)},
  { "ENCODE",		SYM(ENCODE_SYM)},
  { "ENCRYPT",		SYM(ENCRYPT)},
  { "ENDPOINT",		F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_endpoint)},
  { "ENVELOPE",		F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_envelope)},
  { "EQUALS",		F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_equals)},
  { "EXTERIORRING",	F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_exteriorring)},
  { "EXTRACT",		SYM(EXTRACT_SYM)},
  { "EXP",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_exp)},
  { "EXPORT_SET",	SYM(EXPORT_SET)},
  { "FIELD",		SYM(FIELD_FUNC)},	/* For compability */
  { "FIND_IN_SET",	F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_find_in_set)},
  { "FLOOR",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_floor)},
  { "FORMAT",		SYM(FORMAT_SYM)},
  { "FOUND_ROWS",	F_SYM(FUNC_ARG0),0,CREATE_FUNC(create_func_found_rows)},
  { "FROM_DAYS",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_from_days)},
  { "FROM_UNIXTIME",	SYM(FROM_UNIXTIME)},
  { "GET_LOCK",		F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_get_lock)},
  { "GEOMETRYN",	F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_geometryn)},
  { "GEOMETRYTYPE",	F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_geometry_type)},
  { "GEOMCOLLFROMTEXT",	SYM(GEOMCOLLFROMTEXT)},
  { "GEOMCOLLFROMWKB",	SYM(GEOMFROMWKB)},
  { "GEOMETRYCOLLECTIONFROMTEXT",SYM(GEOMCOLLFROMTEXT)},
  { "GEOMETRYCOLLECTIONFROMWKB",SYM(GEOMFROMWKB)},
  { "GEOMETRYFROMTEXT", SYM(GEOMFROMTEXT)},
  { "GEOMETRYFROMWKB",	SYM(GEOMFROMWKB)},
  { "GEOMFROMTEXT",	SYM(GEOMFROMTEXT)},
  { "GEOMFROMWKB",	SYM(GEOMFROMWKB)},
  { "GLENGTH",		F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_glength)},
  { "GREATEST",		SYM(GREATEST_SYM)},
  { "GROUP_CONCAT",	SYM(GROUP_CONCAT_SYM)},
  { "GROUP_UNIQUE_USERS",	SYM(GROUP_UNIQUE_USERS)},
  { "HEX",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_hex)},
  { "IFNULL",		F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_ifnull)},
  { "INET_ATON",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_inet_aton)},
  { "INET_NTOA",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_inet_ntoa)},
  { "INSTR",		F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_instr)},
  { "INTERIORRINGN",	F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_interiorringn)},
  { "INTERSECTS",	F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_intersects)},
  { "ISCLOSED",		F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_isclosed)},
  { "ISEMPTY",		F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_isempty)},
  { "ISNULL",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_isnull)},
  { "IS_FREE_LOCK",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_is_free_lock)},
  { "IS_USED_LOCK",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_is_used_lock)},
  { "LAST_INSERT_ID",	SYM(LAST_INSERT_ID)},
  { "ISSIMPLE",         F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_issimple)},
  { "LAST_DAY",         F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_last_day)},
  { "LCASE",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_lcase)},
  { "LEAST",		SYM(LEAST_SYM)},
  { "LENGTH",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_length)},
  { "LN",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_ln)},
  { "LINEFROMTEXT",	SYM(LINEFROMTEXT)},
  { "LINEFROMWKB",	SYM(GEOMFROMWKB)},
  { "LINESTRINGFROMTEXT",SYM(LINEFROMTEXT)},
  { "LINESTRINGFROMWKB",SYM(GEOMFROMWKB)},
  { "LOAD_FILE",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_load_file)},
  { "LOCATE",		SYM(LOCATE)},
  { "LOG",		SYM(LOG_SYM)},
  { "LOG2",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_log2)},
  { "LOG10",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_log10)},
  { "LOWER",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_lcase)},
  { "LPAD",		F_SYM(FUNC_ARG3),0,CREATE_FUNC(create_func_lpad)},
  { "LTRIM",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_ltrim)},
  { "MAKE_SET",		SYM(MAKE_SET_SYM)},
  { "MAKEDATE",		F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_makedate)},
  { "MAKETIME",		F_SYM(FUNC_ARG3),0,CREATE_FUNC(create_func_maketime)},
  { "MASTER_POS_WAIT",	SYM(MASTER_POS_WAIT)},
  { "MAX",		SYM(MAX_SYM)},
  { "MBRCONTAINS",	F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_contains)},
  { "MBRDISJOINT",	F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_disjoint)},
  { "MBREQUAL",		F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_equals)},
  { "MBRINTERSECTS",	F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_intersects)},
  { "MBROVERLAPS",	F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_overlaps)},
  { "MBRTOUCHES",	F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_touches)},
  { "MBRWITHIN",	F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_within)},
  { "MD5",              F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_md5)},
  { "MID",		SYM(SUBSTRING)},	/* unireg function */
  { "MIN",		SYM(MIN_SYM)},
  { "MLINEFROMTEXT",	SYM(MLINEFROMTEXT)},
  { "MLINEFROMWKB",	SYM(GEOMFROMWKB)},
  { "MPOINTFROMTEXT",	SYM(MPOINTFROMTEXT)},
  { "MPOINTFROMWKB",	SYM(GEOMFROMWKB)},
  { "MPOLYFROMTEXT",	SYM(MPOLYFROMTEXT)},
  { "MPOLYFROMWKB",	SYM(GEOMFROMWKB)},
  { "MONTHNAME",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_monthname)},
  { "MULTILINESTRINGFROMTEXT",SYM(MLINEFROMTEXT)},
  { "MULTILINESTRINGFROMWKB",SYM(GEOMFROMWKB)},
  { "MULTIPOINTFROMTEXT",SYM(MPOINTFROMTEXT)},
  { "MULTIPOINTFROMWKB",SYM(GEOMFROMWKB)},
  { "MULTIPOLYGONFROMTEXT",SYM(MPOLYFROMTEXT)},
  { "MULTIPOLYGONFROMWKB",SYM(GEOMFROMWKB)},
  { "NOW",		SYM(NOW_SYM)},
  { "NULLIF",		F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_nullif)},
  { "NUMGEOMETRIES",	F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_numgeometries)},
  { "NUMINTERIORRINGS",	F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_numinteriorring)},
  { "NUMPOINTS",	F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_numpoints)},
  { "OCTET_LENGTH",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_length)},
  { "OCT",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_oct)},
  { "ORD",              F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_ord)},
  { "OVERLAPS",		F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_overlaps)},
  { "PERIOD_ADD",	F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_period_add)},
  { "PERIOD_DIFF",	F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_period_diff)},
  { "PI",		F_SYM(FUNC_ARG0),0,CREATE_FUNC(create_func_pi)},
  { "POINTFROMTEXT",	SYM(POINTFROMTEXT)},
  { "POINTFROMWKB",	SYM(GEOMFROMWKB)},
  { "POINTN",		F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_pointn)},
  { "POLYFROMTEXT",	SYM(POLYFROMTEXT)},
  { "POLYFROMWKB",	SYM(GEOMFROMWKB)},
  { "POLYGONFROMTEXT",	SYM(POLYFROMTEXT)},
  { "POLYGONFROMWKB",	SYM(GEOMFROMWKB)},
  { "POSITION",		SYM(POSITION_SYM)},
  { "POW",		F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_pow)},
  { "POWER",		F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_pow)},
  { "QUOTE",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_quote)},
  { "RADIANS",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_radians)},
  { "RAND",		SYM(RAND)},
  { "RELEASE_LOCK",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_release_lock)},
  { "REVERSE",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_reverse)},
  { "ROUND",		SYM(ROUND)},
  { "ROW_COUNT",	SYM(ROW_COUNT_SYM)},
  { "RPAD",		F_SYM(FUNC_ARG3),0,CREATE_FUNC(create_func_rpad)},
  { "RTRIM",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_rtrim)},
  { "SEC_TO_TIME",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_sec_to_time)},
  { "SESSION_USER",	SYM(USER)},
  { "SUBDATE",		SYM(SUBDATE_SYM)},
  { "SIGN",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_sign)},
  { "SIN",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_sin)},
  { "SHA",              F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_sha)},
  { "SHA1",             F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_sha)},
  { "SOUNDEX",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_soundex)},
  { "SPACE",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_space)},
  { "SQRT",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_sqrt)},
  { "SRID",		F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_srid)},
  { "STARTPOINT",	F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_startpoint)},
  { "STD",		SYM(STD_SYM)},
  { "STDDEV",		SYM(STD_SYM)},
  { "STR_TO_DATE",	F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_str_to_date)},
  { "STRCMP",		F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_strcmp)},
  { "SUBSTR",		SYM(SUBSTRING)},
  { "SUBSTRING",	SYM(SUBSTRING)},
  { "SUBSTRING_INDEX",	SYM(SUBSTRING_INDEX)},
  { "SUBTIME",          F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_subtime)},
  { "SUM",		SYM(SUM_SYM)},
  { "SYSDATE",		SYM(NOW_SYM)},
  { "SYSTEM_USER",	SYM(USER)},
  { "TAN",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_tan)},
  { "TIME_FORMAT",	F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_time_format)},
  { "TIME_TO_SEC",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_time_to_sec)},
  { "TIMEDIFF",         F_SYM(FUNC_ARG2),0,CREATE_FUNC(create_func_timediff)},
  { "TO_DAYS",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_to_days)},
  { "TOUCHES",		F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_touches)},
  { "TRIM",		SYM(TRIM)},
  { "UCASE",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_ucase)},
  { "UNCOMPRESS",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_uncompress)},
  { "UNCOMPRESSED_LENGTH", F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_uncompressed_length)},
  { "UNHEX",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_unhex)},
  { "UNIQUE_USERS",	SYM(UNIQUE_USERS)},
  { "UNIX_TIMESTAMP",	SYM(UNIX_TIMESTAMP)},
  { "UPPER",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_ucase)},
  { "UUID",		F_SYM(FUNC_ARG0),0,CREATE_FUNC(create_func_uuid)},
  { "VARIANCE",		SYM(VARIANCE_SYM)},
  { "VERSION",		F_SYM(FUNC_ARG0),0,CREATE_FUNC(create_func_version)},
  { "WEEKDAY",		F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_weekday)},
  { "WEEKOFYEAR",	F_SYM(FUNC_ARG1),0,CREATE_FUNC(create_func_weekofyear)},
  { "WITHIN",		F_SYM(FUNC_ARG2),0,CREATE_FUNC_GEOM(create_func_within)},
  { "X",		F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_x)},
  { "Y",		F_SYM(FUNC_ARG1),0,CREATE_FUNC_GEOM(create_func_y)},
  { "YEARWEEK",		SYM(YEARWEEK)}
};
